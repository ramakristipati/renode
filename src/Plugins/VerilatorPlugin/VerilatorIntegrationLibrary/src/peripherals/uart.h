//
// Copyright (c) 2010-2021 Antmicro
//
// This file is licensed under the MIT License.
// Full license text is available in 'licenses/MIT.txt'.
//
#include "../renode_bus.h"
#include "../buses/bus.h"

// UARTAction must be in sync with Renode's protocol
enum UARTAction
{
    txdRequest = 13,
    rxdRequest = 14
};

struct UART : RenodeAgent
{
    public:
    UART(BaseBus* bus, uint8_t* txd, uint8_t* rxd, uint32_t prescaler, uint32_t tx_reg_addr=4, uint8_t* irq=nullptr);
    void eval();
    uint8_t* txd;
    uint8_t* rxd;
    uint8_t* irq;
    uint32_t prescaler;
    uint32_t tx_reg_addr;
    uint8_t prev_irq;

    private:
    void writeToBus(uint64_t addr, uint64_t value) override;
    void handleCustomRequestType(Protocol* message) override;
    void Txd();
    void Rxd(uint8_t value);
};
