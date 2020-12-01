// Copyright (c) 2019-2020 The DailyCrypto developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TOPBAR_H
#define TOPBAR_H

#include <QWidget>
#include "qt/dailycrypto/pwidget.h"
#include "qt/dailycrypto/lockunlock.h"
#include "qt/walletmodel.h"

#include "amount.h"
#include <QTimer>
#include <QProgressBar>

class DailyCryptoGUI;
class WalletModel;
class ClientModel;

namespace Ui {
class TopBar;
}

class TopBar : public PWidget
{
    Q_OBJECT

public:
    explicit TopBar(DailyCryptoGUI* _mainWindow, QWidget *parent = nullptr);
    ~TopBar();

    void showTop();
    void showBottom();

    void loadWalletModel() override;
    void loadClientModel() override;
    void encryptWallet();
    void hdShowMnemonicSeed(bool firstRun);

public slots:
    void updateBalances(const CAmount& balance, const CAmount& unconfirmedBalance, const CAmount& immatureBalance, const CAmount& LockedCollateralBalance,
                        const CAmount& zerocoinBalance, const CAmount& unconfirmedZerocoinBalance, const CAmount& immatureZerocoinBalance,
                        const CAmount& watchOnlyBalance, const CAmount& watchUnconfBalance, const CAmount& watchImmatureBalance,
                        const CAmount& delegatedBalance, const CAmount& coldStakedBalance);
    void updateDisplayUnit();

    void setNumConnections(int count);
    void setNumBlocks(int count);
    void updateAutoMintStatus();
    void setHDStatus(int hdEnabled);
    void setStakingStatusActive(bool fActive);
    void updateStakingStatus();

signals:
    void themeChanged(bool isLight);
    void walletSynced(bool isSync);
    void onShowHideColdStakingChanged(bool show);
    void hdEnabledStatusChanged(int hdEnabled);
    
protected:
    void resizeEvent(QResizeEvent *event) override;
private slots:
    void onBtnReceiveClicked();
    void onThemeClicked();
    void onHdWalletClicked();
    void onBtnLockClicked();
    void lockDropdownMouseLeave();
    void lockDropdownClicked(const StateClicked&);
    void refreshStatus();
    void openLockUnlock();
    void onColdStakingClicked();
    void refreshProgressBarSize();
    void expandSync();
private:
    Ui::TopBar *ui;
    LockUnlock *lockUnlockWidget = nullptr;
    QProgressBar* progressBar = nullptr;

    int nDisplayUnit = -1;
    QTimer* timerStakingIcon = nullptr;
    bool isInitializing = true;
};

#endif // TOPBAR_H
