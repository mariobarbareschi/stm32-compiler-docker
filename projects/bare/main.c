#define uint32_t unsigned int
#define uint16_t unsigned short int

struct GpioPeripheral
{
    volatile uint32_t MODER;    /*GPIO port mode register, offset: 0x00*/
    volatile uint32_t OTYPER;   /*GPIO port output type register offset: 0x04*/
    volatile uint32_t OSPEEDR;  /*GPIO port output speed register offset: 0x08*/
    volatile uint32_t PUPDR;    /*GPIO port pull-up/pull-down register, offset: 0x0C*/
    volatile uint32_t IDR;      /*GPIO port input data register, offset: 0x10 */
    volatile uint32_t ODR;      /*GPIO port output data register, offset: 0x14 */
    volatile uint32_t BSRR;     /*GPIO port bit set/reset register, offset: 0x18 */
    volatile uint32_t LCKR;     /*GPIO port configuration lock register, offset: 0x1C */
    volatile uint32_t AFR[2];   /*GPIO alternate function registers, offset: 0x20-0x24 */
};

#define PERIPH_BASE        ((uint32_t)0x40000000)
#define APB1PERIPH_BASE     (PERIPH_BASE)
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x00020000)

#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00U)

#define GPIO ((struct GpioPeripheral *)GPIOD_BASE)

#define LED4_PIN 0x1<<12
#define LED3_PIN 0x1<<13
#define LED6_PIN 0x1<<14
#define LED7_PIN 0x1<<15

#define  GPIO_MODE_OUTPUT_PP ((uint32_t)0x00000001U) /*Output Push Pull Mode */
/* Reset and Clock Control (RCC) */

#define RCC_BASE            (AHB1PERIPH_BASE + 0x3800)                  /* Reset and Clock Control base address */

#define RCC_CR              *(volatile uint32_t *) (RCC_BASE + 0x00)    /* Clock Control Register */
#define RCC_AHB1ENR         *(volatile uint32_t *) (RCC_BASE + 0x30)    /* AHB1 Enable Register */

int main(){
    // enable clock to GPIOD
    RCC_AHB1ENR |= (0x1 << 3);
    
    /*
        configure PD.15 as general purpose output
    */
    GPIO->MODER |= (0x1 << 30);
    GPIO->MODER &= ~(0x1 << 31);
    
    /*
        GPIOs output type: Push-Pull
        so that it can be pulled high (logic-1) and pulled down (logic-0)
    */
    GPIO->OTYPER &= ~LED7_PIN;
    
    /*
        Lets keep GPIO speed: Medium
    */
    GPIO->OSPEEDR = (0x1 << 30);
    GPIO->OSPEEDR &= ~(0x1 << 31);
    
    /*
    Initial Level: Logic High --> No Pull-up/down
    */
    GPIO->PUPDR = (0x1 << 30);
    GPIO->PUPDR &= ~(0x1 << 31);
    
    
    while (1) {
       GPIO->ODR ^= LED7_PIN;
       int i;
       for ( i = 0; i < 100000; ++i);
    }

    return 0;
}