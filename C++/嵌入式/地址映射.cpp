/* 1. 定义物理地址，建议加上 U 后缀表示无符号 */
#define PERIPH_REG_ADDR   0x40021000U

/* 2. 定义映射宏：强转为 volatile 指针并解引用 */
/* 注意：外层括号和内部强转的括号都不能少，以保证宏安全 */
#define PERIPH_REG        (*((volatile uint32_t *)PERIPH_REG_ADDR))

/* 3. 写入数据 */
void write_periph(void) {
    // 像操作普通变量一样写入
    PERIPH_REG = 0x55AAU; 
}