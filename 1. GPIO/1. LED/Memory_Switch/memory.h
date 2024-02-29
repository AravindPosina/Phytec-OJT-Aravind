void Enable(void);
void swii(void);

#define PERIPH_BASE             (0x40000000UL)
#define AHB1PERIPH_OFFSET       (0x2000UL)
#define AHB1_BASE               (PERIPH_BASE+AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET            (0X00000000UL)
#define GPIOA_BASE              (AHB1_BASE+GPIOA_OFFSET)
#define GPIOC_OFFSET            (0X00000800UL)
#define GPIOC_BASE              (AHB1_BASE+GPIOC_OFFSET)
#define RCC_OFFSET              (0X3800UL)
#define RCC_BASE                (AHB1_BASE+RCC_OFFSET)
