// Poker Hands （扑克牌型）  
// PC/UVa IDs: 110202/10315, Popularity: C, Success rate: average Level: 2  
// Verdict: Accepted  
// Submission Date: 2011-05-23  
// UVa Run Time: 0.008s  
//  
// 版权所有（C）2011，邱秋。metaphysis # yeah dot net  
//  
// 计算每手牌的值，先将牌按从大到小排序。可以将牌的数值看成15进制系统。对于一手牌按 15  
// 进制来计算它的值，将其转换成一个整数来比较大小。例如：  
//  
// 2H 3H 4H 5H 6H  
//  
// 是同花顺，则将其转换成15进制数为：  
//  
// 6 * 15^4 + 5 * 15^3 + 4 * 15^2 + 3 * 15^1 + 2 * 15^0 = （65432）（15）  
//  
// 每一种牌的类型表示成进位，如 STRAIGHT_FLUSH 的进位为 8，则最终牌面值乘以 15^8,保证了类型  
// 较高的牌面值肯定会大于类型较低的牌面值。则 2H 3H 4H 5H 6H 的最终牌面值为：  
//  
// （6 * 15^4 + 5 * 15^3 + 4 * 15^2 + 3 * 15^1 + 2 * 15^0） * 15^8 =   
// （6543200000000）（15）  
      
#include <iostream>  
#include <sstream>  
#include <algorithm>  
#include <cmath>  
      
using namespace std;  
      
#define HIGH_CARD   0  
#define PAIR        1  
#define TWO_PAIR    2  
#define THREE_KIND  3  
#define STRAIGHT    4  
#define FLUSH       5  
#define FULL_HOUSE  6  
#define FOUR_KIND   7  
#define STRAIGHT_FLUSH  8  
  
#define TIE     0  
#define BLACK_WIN   1  
#define WHITE_WIN   2  
      
#define BASE        15  
#define CARDS       5  
      
#ifndef DEBUG_MODE  
// #define DEBUG_MODE  
#endif  
      
#ifdef DEBUG_MODE  
string type[STRAIGHT_FLUSH + 1] = {"HIGH_CARD", "PAIR", "TWO_PAIR", "THREE_KIND",  
    "STRAIGHT", "FLUSH", "FULL_HOUSE", "FOUR_KIND", "STRAIGHT_FLUSH"};  
#endif  
      
// 将牌面字符转换成数字。T = 10，J = 11，Q = 12，K = 13，A = 14。     
int convert(char c)  
{  
    string cards = "23456789TJQKA";  
  
    for (int i = 0; i < cards.length(); i++)  
        if (c == cards[i])  
            return (i + 2);  
}  
      
// 排序比较函数，大的数在前。  
bool cmp(int a, int b)  
{  
    return a > b;  
}  
      
// 对牌面值按从大到小排序。  
void sort_card(string hands[], int *card)  
{  
    for (int i = 0; i < CARDS; i++)  
        card[i] = convert(hands[i][0]);  
          
    sort(card, card + CARDS, cmp);  
}  
      
// 按类型 type 将牌面值转换成一个整数值。  
long long unsigned get_score(int *card, int type)  
{  
    long long unsigned score = 0;  
    for (int i = 0; i < CARDS; i++)  
        score = score * BASE + card[i];  
    return score * pow(BASE, type);  
}  
      
// 交换两个数。  
void swap(int &a, int &b)  
{  
    int tmp = a;  
    a = b;  
    b = tmp;  
}  
      
// 判断牌面属于何种类型。确定类型后，将关键牌移往前面，非关键牌按从大到小顺序排列。  
long long unsigned card_type(int *card, int type, string hands[])  
{  
    bool flag;  
    char suit;  
      
    switch (type)  
    {  
        case HIGH_CARD:  
            return get_score(card, HIGH_CARD);  
              
        case  PAIR:  
            for (int i = 0; i < CARDS; i++)  
                if (card[i] == card[i + 1])  
                {  
                    if (i > 0)  
                    {  
                        swap(card[i], card[0]);  
                        swap(card[i + 1], card[1]);  
                    }  
              
                    return get_score(card, PAIR);  
                }  
            break;  
          
        case TWO_PAIR:  
            for (int i = 0; i < CARDS - 2; i++)  
                if (card[i] == card[i + 1])  
                {  
                    for (int j = i + 2; j < CARDS; j++)  
                        if (card[j] == card[j + 1])  
                        {  
                            if (i > 0)  
                            {  
                                swap(card[i], card[0]);  
                                swap(card[i + 1], card[1]);  
                            }  
                            if (j > 2)  
                            {  
                                swap(card[j], card[2]);  
                                swap(card[j + 1], card[3]);  
                            }  
                      
                            return get_score(card, TWO_PAIR);  
                        }  
                }  
            break;  
              
        case THREE_KIND:  
            for (int i = 0; i < CARDS - 2; i++)  
                if (card[i] == card[i + 2])  
                {  
                    if (i > 0)  
                    {  
                        swap(card[i], card[0]);  
                        swap(card[i + 1], card[1]);  
                        swap(card[i + 2], card[2]);  
                    }  
              
                    return get_score(card, THREE_KIND);  
                }  
            break;  
              
        case STRAIGHT:  
            flag = true;  
            for (int i = 0; i < CARDS - 1; i++)  
                if (card[i] != (card[i + 1] + 1))  
                {  
                    flag = false;  
                    break;  
                }  
      
            if (flag)  
                return get_score(card, STRAIGHT);  
            break;  
              
        case FLUSH:  
            flag = true;  
            suit = hands[0][1];  
            for (int i = 1; i < CARDS; i++)  
                if (suit != hands[i][1])  
                {  
                    flag = false;  
                    break;  
                }  
            if (flag)  
                return get_score(card, FLUSH);  
            break;  
              
        case FULL_HOUSE:  
            if (card[0] == card[2] && card[3] == card[4])  
                return get_score(card, FULL_HOUSE);  
  
            if (card[0] == card[1] && card[2] == card[4])  
            {  
                swap(card[2], card[0]);  
                swap(card[3], card[1]);  
                swap(card[4], card[2]);  
                  
                return get_score(card, FULL_HOUSE);  
            }  
              
            break;  
              
        case FOUR_KIND:  
            for (int i = 0; i < CARDS - 3; i++)  
                if (card[i] == card[i + 3])  
                {  
                    if (i > 0)  
                    {  
                        swap(card[i], card[0]);  
                        swap(card[i + 1], card[1]);  
                        swap(card[i + 2], card[2]);  
                        swap(card[i + 3], card[3]);  
                    }  
                    return get_score(card, FOUR_KIND);  
                }  
            break;  
              
        case STRAIGHT_FLUSH:  
            if (card_type(card, STRAIGHT, hands) &&   
                        card_type(card, FLUSH, hands))  
                return get_score(card, STRAIGHT_FLUSH);  
            break;  
        }  
          
    return 0;  
}  
      
// 获取一手牌的最大类型及其值。  
long long unsigned get_value(string hands[])  
{  
    int card[5];  
    sort_card(hands, card);  
      
    long long unsigned value = 0;  
    for (int i = 8; i >= 0; i--)  
    {  
        value = card_type(card, i, hands);  
      
        if (value)  
        {  
        #ifdef DEBUG_MODE  
            cout << endl;  
            cout << "<Debug Begin>" << endl;  
            for (int j = 0; j < CARDS; j++)  
                cout << hands[j] << " ";  
            cout << endl;  
            for (int j = 0; j < CARDS; j++)  
                cout << card[j] << " ";  
            cout << endl;  
            cout << "CARD TYPE: " << type[i] << endl;  
            cout << "VALUE: " << value << endl;  
            cout << "<Debug End>" << endl;  
            cout << endl;  
        #endif  
              
            return value;  
        }  
    }  
}  
      
// 比较两手牌的大小，直接比较其值的大小即可。  
int compare_card(string f_hands[], string s_hands[])  
{  
    long long unsigned f_value, s_value;  
    f_value = get_value(f_hands);  
    s_value = get_value(s_hands);  
      
    return (f_value == s_value) ? (TIE) : ((f_value > s_value) ?   
                        (BLACK_WIN) : (WHITE_WIN));  
}  
      
int main(int argc, char *argv[])  
{  
    string f_hands[5], s_hands[5], line;  
    string info[3] = { "none", "left", "right" };  
    freopen(argv[1], "r", stdin);  
    while (getline(cin, line))  
    {  
        istringstream iss(line);  
  
        for (int i = 0; i < 5; i++)  
            iss >> f_hands[i];  
        for (int i = 0; i < 5; i++)  
            iss >> s_hands[i];  
  
        cout << info[compare_card(f_hands, s_hands)] << endl;  
    }  
      
    return 0;  
}  