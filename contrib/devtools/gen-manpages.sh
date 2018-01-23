#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

WIFICOIND=${WIFICOIND:-$SRCDIR/wificoind}
WIFICOINCLI=${WIFICOINCLI:-$SRCDIR/wificoin-cli}
WIFICOINTX=${WIFICOINTX:-$SRCDIR/wificoin-tx}
WIFICOINQT=${WIFICOINQT:-$SRCDIR/qt/wificoin-qt}

[ ! -x $WIFICOIND ] && echo "$WIFICOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
WFCVER=($($WIFICOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for wificoind if --version-string is not set,
# but has different outcomes for wificoin-qt and wificoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$WIFICOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $WIFICOIND $WIFICOINCLI $WIFICOINTX $WIFICOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${WFCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${WFCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
