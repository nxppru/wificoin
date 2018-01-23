// Copyright (c) 2011-2014 The WiFicoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef WIFICOIN_QT_WIFICOINADDRESSVALIDATOR_H
#define WIFICOIN_QT_WIFICOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class WiFicoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit WiFicoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** WiFicoin address widget validator, checks for a valid wificoin address.
 */
class WiFicoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit WiFicoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // WIFICOIN_QT_WIFICOINADDRESSVALIDATOR_H
