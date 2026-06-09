#include <iostream>
#include <cassert>
#include <cstdint>

/**
 * ============================================================================
 *                       W1 嵌入式特色手撕专项：寄存器操作
 * ============================================================================
 * 【学习提示】
 *   - 本模板用于练习位操作宏、位计数、二进制逆序、奇偶位交换、大小端判定与转换。
 *   - 所有题目均留有 "TODO: 请在这里实现你的代码" 区域。
 *   - 运行方式：
 *         g++ -O3 寄存器操作.cpp -o reg_test
 *         ./reg_test
 *   - 当且仅当所有 assert 通过，且控制台输出 "恭喜！寄存器操作专项所有测试圆满通过！" 时代表通关。
 * 
 * 【高频面试口述题（请在脑海中尝试用中文脱稿回答 ≥2 分钟）】
 *   1. 宏定义时，为什么每个参数和整个宏体外部都要加括号？
 *   2. 宏定义中，1 << 31 为什么是不安全的？应该怎么写？（提示：1U）
 *   3. 为什么在寄存器映射和中断服务程序中，共享变量必须声明为 volatile？它能防止多线程竞争吗？
 * ============================================================================
 */

// ============================================================================
// 练习 1：经典位操作宏实现（附录 C.7 基础）
// ============================================================================
// 要求：
// 1. 实现以下四个宏：
//    - SET_BIT(reg, k): 将 reg 的第 k 位置 1，其余位不变
//    - CLEAR_BIT(reg, k): 将 reg 的第 k 位置 0，其余位不变
//    - TOGGLE_BIT(reg, k): 翻转 reg 的第 k 位，其余位不变
//    - GET_BIT(reg, k): 获取 reg 的第 k 位的值（返回 0 或 1）
// 2. 注意事项：必须使用极其安全的括号包裹（参数与整体），移位操作应使用 1U 以防止符号位溢出。
// ============================================================================

// TODO: 请在这里实现你的宏定义
#define SET_BIT(reg, k)     ((reg) |= (1U << (k)))
#define CLEAR_BIT(reg, k)   ((reg) &= ~(1U << (k)))
#define TOGGLE_BIT(reg, k)  ((reg) ^= ((1U) << (k)))
#define GET_BIT(reg, k)     (((reg) >> (k)) & 1U) 

void test_bit_macros() {
    uint32_t reg = 0x00000000U;
    
    // 测试 SET_BIT
    SET_BIT(reg, 5);
    assert(reg == 0x00000020U);
    SET_BIT(reg, 31); // 测试最高位
    assert(reg == 0x80000020U);
    
    // 测试 GET_BIT
    assert(GET_BIT(reg, 5) == 1U);
    assert(GET_BIT(reg, 4) == 0U);
    assert(GET_BIT(reg, 31) == 1U);
    
    // 测试 TOGGLE_BIT
    TOGGLE_BIT(reg, 5);
    assert(reg == 0x80000000U);
    TOGGLE_BIT(reg, 4);
    assert(reg == 0x80000010U);
    
    // 测试 CLEAR_BIT
    CLEAR_BIT(reg, 31);
    assert(reg == 0x00000010U);
    CLEAR_BIT(reg, 4);
    assert(reg == 0x00000000U);
    
    std::cout << "[练习 1] 位操作宏测试通过！" << std::endl;
}

// ============================================================================
// 练习 2：32 位无符号整数中“1”的个数（Hamming Weight - LC 191 特化）
// ============================================================================
// 题目要求：
// 实现以下两个函数：
// 1. count_ones_lowbit(uint32_t n)：
//    - 利用位运算技巧：n &= (n - 1) 能消去二进制中最右侧的一个 1。
//    - 时间复杂度应为 O(k)，其中 k 是 1 的个数。
// 
// 2. count_ones_parallel(uint32_t n)：
//    - 【大厂笔试常客】分治并行计数法。
//    - 禁止使用任何循环（for, while），在 O(1) 的时间内完成 32 位的计数。
//    - 提示：分别对相邻的 1位、2位、4位、8位、16位进行掩码求和。
// ============================================================================

// TODO: 实现 O(k) 查空算法
int count_ones_lowbit(uint32_t n) {
    int count = 0;
    while(n > 0)
    {
        n &= (n-1);
        count++;
    }
    return count;
}

// TODO: 实现 O(1) 分治并行计数算法（不准用任何循环）
int count_ones_parallel(uint32_t n) {
    n = (n & 0x55555555U) + ((n >> 1) & 0x55555555U);  // 两两归并
    n = (n & 0x33333333U) + ((n >> 2) & 0x33333333U);  // 四四归并
    n = (n & 0x0F0F0F0FU) + ((n >> 4) & 0x0F0F0F0FU);  // 八八归并
    n = (n & 0x00FF00FFU) + ((n >> 8) & 0x00FF00FFU);  // 十六位归并
    n = (n & 0x0000FFFFU) + ((n >> 16) & 0x0000FFFFU); // 三十二位归并
    return (int)n;
}

void test_count_ones() {
    uint32_t n1 = 0x00000000U;
    uint32_t n2 = 0x00000001U;
    uint32_t n3 = 0xF000000FU; // 1111 0000 ... 0000 1111 (8个1)
    uint32_t n4 = 0xFFFFFFFFU; // 32个1
    uint32_t n5 = 0x55555555U; // 16个1
    
    assert(count_ones_lowbit(n1) == 0);
    assert(count_ones_lowbit(n2) == 1);
    assert(count_ones_lowbit(n3) == 8);
    assert(count_ones_lowbit(n4) == 32);
    assert(count_ones_lowbit(n5) == 16);
    
    assert(count_ones_parallel(n1) == 0);
    assert(count_ones_parallel(n2) == 1);
    assert(count_ones_parallel(n3) == 8);
    assert(count_ones_parallel(n4) == 32);
    assert(count_ones_parallel(n5) == 16);
    
    std::cout << "[练习 2] 1的个数位计数测试通过！" << std::endl;
}

// ============================================================================
// 练习 3：寄存器高低位翻转（Reverse Bits - LC 190 特化）
// ============================================================================
// 题目要求：
// 实现以下两个函数：
// 1. reverse_bits_loop(uint32_t n)：
//    - 逐位移动，将 n 的 bit0 移动到新数的 bit31，将 bit1 移动到 bit30，依次类推。
//    - 时间复杂度 O(32)。
// 
// 2. reverse_bits_parallel(uint32_t n)：
//    - 【大厂进阶】折半交换分治法（不使用任何循环，在 O(1) 时间内完成逆序）。
//    - 提示：类似于归并排序，先左右 16 位交换，然后每 8 位内部左右 4 位交换，依次向下，直到相邻 bit 交换。
// ============================================================================

// TODO: 实现逐位搬移翻转（循环实现）
uint32_t reverse_bits_loop(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; i++) {
        res <<= 1;          // 1. 新数腾出最右边的一位空位
        res |= (n & 1U);    // 2. 取出旧数的当前最低位，拼接到新数的最右边
        n >>= 1;            // 3. 旧数右移一位，丢弃已经处理过的最低位
    }
    return res;
}

// TODO: 实现折半交换分治翻转（不准用任何循环）
uint32_t reverse_bits_parallel(uint32_t n) {
    // 1. 交换高低 16 位
    n = (n >> 16) | (n << 16);
    
    // 2. 交换相邻的 8 位字节（掩码 0xFF00FF00 提取高 8 位）
    n = ((n & 0xFF00FF00U) >> 8) | ((n & 0x00FF00FFU) << 8);
    
    // 3. 交换相邻的 4 位半字节（掩码 0xF0F0F0F0）
    n = ((n & 0xF0F0F0F0U) >> 4) | ((n & 0x0F0F0F0FU) << 4);
    
    // 4. 交换相邻的 2 位（掩码 0xCCCCCCCC / 0x33333333）
    n = ((n & 0xCCCCCCCCU) >> 2) | ((n & 0x33333333U) << 2);
    
    // 5. 交换相邻的单 bit（即奇偶位互换，掩码 0xAAAAAAAA / 0x55555555）
    n = ((n & 0xAAAAAAAAU) >> 1) | ((n & 0x55555555U) << 1);
    
    return n;
}

void test_reverse_bits() {
    uint32_t n1 = 0x00000000U;
    uint32_t n2 = 0x80000000U; // 反转后应为 0x00000001U
    uint32_t n3 = 0x12345678U; // 反转后：0x1E6A2C48U
    uint32_t n4 = 0xAAAAAAAAU; // 10101010... 反转后：0x55555555U
    
    assert(reverse_bits_loop(n1) == 0x00000000U);
    assert(reverse_bits_loop(n2) == 0x00000001U);
    assert(reverse_bits_loop(n3) == 0x1E6A2C48U);
    assert(reverse_bits_loop(n4) == 0x55555555U);
    
    assert(reverse_bits_parallel(n1) == 0x00000000U);
    assert(reverse_bits_parallel(n2) == 0x00000001U);
    assert(reverse_bits_parallel(n3) == 0x1E6A2C48U);
    assert(reverse_bits_parallel(n4) == 0x55555555U);
    
    std::cout << "[练习 3] 寄存器位翻转测试通过！" << std::endl;
}

// ============================================================================
// 练习 4：互换奇偶位（大疆、联发科经典笔试手撕）
// ============================================================================
// 题目要求：
// 实现函数 swap_odd_even_bits(uint32_t n)：
// - 给定一个 32 位无符号整数 n，将它的所有奇数位和偶数位互换。
// - 例如，bit0 与 bit1 互换，bit2 与 bit3 互换……
// - 时间复杂度要求必须是 O(1)，不能使用循环。
// - 提示：利用掩码 0xAAAAAAAA 获取所有奇数位，0x55555555 获取所有偶数位，进行适当移位后再合并。
// ============================================================================

// TODO: 实现奇偶位交换算法（禁止循环，O(1)）
uint32_t swap_odd_even_bits(uint32_t n) {
    return ((n & 0xAAAAAAAAU) >> 1) | ((n & 0x55555555U) << 1);

}

void test_swap_odd_even() {
    uint32_t n1 = 0xAAAAAAAAU; // 1010...1010，交换后应为 0x55555555U (0101...0101)
    uint32_t n2 = 0x55555555U; // 交换后应为 0xAAAAAAAAU
    uint32_t n3 = 0x12345678U; // 二进制：0001 0010 0011 0100 0101 0110 0111 1000
                               // 奇偶互换：0010 0001 0011 1000 1010 1001 1011 0100
                               // 十六进制：0x2138A9B4U
    
    assert(swap_odd_even_bits(n1) == 0x55555555U);
    assert(swap_odd_even_bits(n2) == 0xAAAAAAAAU);
    assert(swap_odd_even_bits(n3) == 0x2138A9B4U);
    
    std::cout << "[练习 4] 互换奇偶位测试通过！" << std::endl;
}

// ============================================================================
// 练习 5：大小端自测与网络字节序转换
// ============================================================================
// 题目要求：
// 1. is_little_endian()：
//    - 利用 C/C++ 中 Union 共享内存的特性（或指针强转方式），测试当前运行系统是否为小端。
//    - 小端系统返回 true，大端系统返回 false。
// 
// 2. swap_bytes_32(uint32_t n)：
//    - 手写实现 32 位无符号整数的字节序翻转（模拟 htonl/ntohl 行为）。
//    - 例如输入 0x12345678，输出应为 0x78563412。
//    - 要求：使用位移和位掩码，不使用任何 C/C++ 库函数。
// ============================================================================

// TODO: 使用联合体或指针类型转换，判断系统大小端
bool is_little_endian() {
    union {
        uint32_t i;
        char c[4];
    } u;
    u.i = 1;
    return u.c[0] == 1; // 小端系统返回 true，大端系统返回 false。

}

// TODO: 手写 32 位整数字节序翻转
uint32_t swap_bytes_32(uint32_t n) {
    return ((n >> 24) & 0x000000FFU) | // B3 挪到 B0
           ((n >> 8)  & 0x0000FF00U) | // B2 挪到 B1
           ((n << 8)  & 0x00FF0000U) | // B1 挪到 B2
           ((n << 24) & 0xFF000000U);  // B0 挪到 B3
}

void test_endianness() {
    // 1. 测试大小端。由于目前几乎所有的主流个人 PC (Windows/Linux/MacOS x86_64/ARM64) 均为小端系统，我们断言其为小端。
    assert(is_little_endian() == true);
    
    // 2. 字节序翻转测试
    uint32_t val = 0x12345678U;
    uint32_t swapped = swap_bytes_32(val);
    assert(swapped == 0x78563412U);
    
    uint32_t val2 = 0x00000001U;
    assert(swap_bytes_32(val2) == 0x01000000U);
    
    std::cout << "[练习 5] 大小端判断与字节序翻转测试通过！" << std::endl;
}

int main() {
    std::cout << "============== 寄存器操作专项测试启动 ==============" << std::endl;
    
    test_bit_macros();
    test_count_ones();
    test_reverse_bits();
    test_swap_odd_even();
    test_endianness();
    
    std::cout << "====================================================" << std::endl;
    std::cout << "恭喜！寄存器操作专项所有测试圆满通过！请继续挑战字段赋值！" << std::endl;
    std::cout << "====================================================" << std::endl;
    
    return 0;
}
