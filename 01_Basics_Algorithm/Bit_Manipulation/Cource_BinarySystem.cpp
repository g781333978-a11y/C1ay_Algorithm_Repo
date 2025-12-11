/**
 * @Title: 熟悉二进制的相关运算
 * @Author: C1ay
 * @Date: 2025-12-09 21:30
 * @Tag: 二进制运算
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
    // 辅助函数：打印整数的32位二进制形态
    static void printBinary(int num)
    {
        // 从最高位（第31位）开始，一直遍历到第0位
        for (int i = 31; i >= 0; --i)
        {
            // 1 << i ：将1左移i位，构造探测掩码（只有第i位是1，其余是0）
            // num & (1 << i)：检查num的第i位是否为1
            cout << ((num & (1 << i)) == 0 ? '0' : '1');
        }
        cout << endl;
    }

    // 用于测试短路求值的辅助函数
    static bool returnTrue()
    {
        cout << "进入了returnTrue函数" << endl;
        return true;
    }

    static bool returnFalse()
    {
        cout << "进入了returnFalse函数" << endl;
        return false;
    }
};

int main() {
    // IO 性能优化，加快 cin/cout 速度
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // ------------------------------------------------------
    // 1. 基础正数与二进制
    // ------------------------------------------------------
    int a = 78;
    cout << a << endl;
    Solution::printBinary(a); 
    cout << "===a===" << endl;

    // ------------------------------------------------------
    // 2. 负数的存储（补码 Two's Complement）
    // ------------------------------------------------------
    // 计算机底层统一使用补码。
    // -6 的补码 = 6的二进制取反 + 1
    int b = -6;
    cout << b << endl;
    Solution::printBinary(b); // 输出形如 111...1010
    cout << "===b===" << endl;

    // ------------------------------------------------------
    // 3. 不同进制的字面量定义
    // ------------------------------------------------------
    // 0b 开头表示二进制字面量 (C++14 标准引入)
    int c = 0b1001110; 
    cout << c << endl; // 输出十进制 78
    Solution::printBinary(c);
    cout << "===c===" << endl;

    // 0x 开头表示十六进制字面量
    int d = 0x4e; 
    cout << d << endl; // 0x4e = 4*16 + 14 = 78
    Solution::printBinary(d);
    cout << "===d===" << endl;

    // ------------------------------------------------------
    // 4. 按位取反(~) 与 相反数(-) 的关系
    // ------------------------------------------------------
    // 核心公式：-x = ~x + 1
    cout << a << endl;
    Solution::printBinary(a);   // 原数
    Solution::printBinary(~a);  // 按位取反（符号位也会变）
    
    int e1 = ~a + 1;            // 手动计算相反数
    cout << e1 << endl;         // 输出 -78
    Solution::printBinary(e1);
    
    int e2 = -a;                // 系统计算相反数
    cout << e2 << endl;
    Solution::printBinary(e1);  // 结果与 e1 一致
    cout << "===e===" << endl;

    // ------------------------------------------------------
    // 5. 特殊情况：INT_MIN 的溢出
    // ------------------------------------------------------
    // int范围: -2^31 ~ 2^31 - 1
    // 最小值没有对应的正数（正数最大只到 2^31 - 1）
    int f = INT_MIN; 
    cout << f << endl;
    Solution::printBinary(f);   // 1000...0000

    // 取反逻辑：
    // -INT_MIN 在数学上是 2^31，但 int 存不下，发生溢出
    // 溢出后通常回绕回 INT_MIN 自身
    cout << -f << endl;         
    Solution::printBinary(-f);  // 依然是 1000...0000

    // 公式验证：~f 是 0111...1111 (即 INT_MAX)
    // INT_MAX + 1 发生溢出，变成 INT_MIN
    cout << (~f + 1) << endl;   
    Solution::printBinary(~f + 1);
    cout << "===f===" << endl;

    // ------------------------------------------------------
    // 6. 位运算基础逻辑符 ( | & ^ )
    // ------------------------------------------------------
    int g = 0b0001010;
    int h = 0b0001100;
    Solution::printBinary(g | h); // 或：有1则1 -> 0001110
    Solution::printBinary(g & h); // 与：全1则1 -> 0001000
    Solution::printBinary(g ^ h); // 异或：不同则1 -> 0000110 (无进位加法)
    cout << "===g、h===" << endl;

    // ------------------------------------------------------
    // 7. 左移操作 (<<)
    // ------------------------------------------------------
    // 规则：高位丢弃，低位补0。数值上等同于 * 2^n
    int i = 0b0011010;
    Solution::printBinary(i);
    Solution::printBinary(i << 1); 
    Solution::printBinary(i << 2);
    Solution::printBinary(i << 3);
    cout << "===i << ===" << endl;

    // ------------------------------------------------------
    // 8. 右移操作 (>> vs >>>)
    // ------------------------------------------------------
    // C++ 中对于有符号数(int)，>> 通常是"算术右移"（Arithmetic Shift）
    // 规则：低位丢弃，高位补符号位（正数补0，负数补1）
    
    // 正数右移：补0
    Solution::printBinary(i);
    Solution::printBinary(i >> 2);
    // C++没有 >>> 运算符。要实现"逻辑右移"（高位一律补0），需先强转为 unsigned
    Solution::printBinary(static_cast<unsigned int>(i) >> 2); 
    cout << "===i >> >>>===" << endl;

    // 负数右移：补1（保持负号）
    int j = 0b11110000000000000000000000000000; // 一个很大的负数
    Solution::printBinary(j);
    Solution::printBinary(j >> 2); // 高位补1，结果仍为负
    
    // 模拟 Java 的 >>> (无符号右移)：强转 unsigned 后右移，高位补0
    Solution::printBinary(static_cast<unsigned int>(j) >> 2); 
    cout << "===j >> >>>===" << endl;

    // ------------------------------------------------------
    // 9. 位移与乘除法的关系
    // ------------------------------------------------------
    int k = 10;
    cout << k << endl;
    cout << (k << 1) << endl; // 10 * 2 = 20
    cout << (k << 2) << endl; // 10 * 4 = 40
    cout << (k << 3) << endl; // 10 * 8 = 80
    cout << (k >> 1) << endl; // 10 / 2 = 5
    cout << (k >> 2) << endl; // 10 / 4 = 2 (向下取整)
    cout << (k >> 3) << endl; // 10 / 8 = 1
    cout << "===k===" << endl;

    // ------------------------------------------------------
    // 10. 逻辑运算 vs 位运算 (短路特性演示)
    // ------------------------------------------------------
    // 重点：位运算符 (| , &) 会计算两边的表达式
    //      逻辑运算符 (||, &&) 具有"短路"（Short-circuit）特性
    
    cout << "test1测试开始 (位运算 | )" << endl;
    // 位运算 | ：没有短路，两边都会执行。returnFalse() 也会被打印。
    bool test1 = Solution::returnTrue() | Solution::returnFalse();
    cout << "test1结果，" << test1 << endl;

    cout << "test2测试开始 (逻辑运算 || )" << endl;
    // 逻辑运算 || ：如果左边为 true，结果已定，右边不再执行（短路）。
    // returnFalse() 不会执行。
    bool test2 = Solution::returnTrue() || Solution::returnFalse();
    cout << "test2结果，" << test2 << endl;

    cout << "test3测试开始 (位运算 & )" << endl;
    // 位运算 & ：没有短路，两边都会执行。
    bool test3 = Solution::returnFalse() & Solution::returnTrue();
    cout << "test3结果，" << test3 << endl;

    cout << "test4测试开始 (逻辑运算 && )" << endl;
    // 逻辑运算 && ：如果左边为 false，结果已定，右边不再执行（短路）。
    // returnTrue() 不会执行。
    bool test4 = Solution::returnFalse() && Solution::returnTrue();
    cout << "test4结果，" << test4 << endl;
    cout << "===|、&、||、&&===" << endl;

    return 0;
}