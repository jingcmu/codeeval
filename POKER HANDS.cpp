// Poker Hands ���˿����ͣ�  
// PC/UVa IDs: 110202/10315, Popularity: C, Success rate: average Level: 2  
// Verdict: Accepted  
// Submission Date: 2011-05-23  
// UVa Run Time: 0.008s  
//  
// ��Ȩ���У�C��2011�����metaphysis # yeah dot net  
//  
// ����ÿ���Ƶ�ֵ���Ƚ��ư��Ӵ�С���򡣿��Խ��Ƶ���ֵ����15����ϵͳ������һ���ư� 15  
// ��������������ֵ������ת����һ���������Ƚϴ�С�����磺  
//  
// 2H 3H 4H 5H 6H  
//  
// ��ͬ��˳������ת����15������Ϊ��  
//  
// 6 * 15^4 + 5 * 15^3 + 4 * 15^2 + 3 * 15^1 + 2 * 15^0 = ��65432����15��  
//  
// ÿһ���Ƶ����ͱ�ʾ�ɽ�λ���� STRAIGHT_FLUSH �Ľ�λΪ 8������������ֵ���� 15^8,��֤������  
// �ϸߵ�����ֵ�϶���������ͽϵ͵�����ֵ���� 2H 3H 4H 5H 6H ����������ֵΪ��  
//  
// ��6 * 15^4 + 5 * 15^3 + 4 * 15^2 + 3 * 15^1 + 2 * 15^0�� * 15^8 =   
// ��6543200000000����15��  
      
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
      
// �������ַ�ת�������֡�T = 10��J = 11��Q = 12��K = 13��A = 14��     
int convert(char c)  
{  
    string cards = "23456789TJQKA";  
  
    for (int i = 0; i < cards.length(); i++)  
        if (c == cards[i])  
            return (i + 2);  
}  
      
// ����ȽϺ������������ǰ��  
bool cmp(int a, int b)  
{  
    return a > b;  
}  
      
// ������ֵ���Ӵ�С����  
void sort_card(string hands[], int *card)  
{  
    for (int i = 0; i < CARDS; i++)  
        card[i] = convert(hands[i][0]);  
          
    sort(card, card + CARDS, cmp);  
}  
      
// ������ type ������ֵת����һ������ֵ��  
long long unsigned get_score(int *card, int type)  
{  
    long long unsigned score = 0;  
    for (int i = 0; i < CARDS; i++)  
        score = score * BASE + card[i];  
    return score * pow(BASE, type);  
}  
      
// ������������  
void swap(int &a, int &b)  
{  
    int tmp = a;  
    a = b;  
    b = tmp;  
}  
      
// �ж��������ں������͡�ȷ�����ͺ󣬽��ؼ�������ǰ�棬�ǹؼ��ư��Ӵ�С˳�����С�  
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
      
// ��ȡһ���Ƶ�������ͼ���ֵ��  
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
      
// �Ƚ������ƵĴ�С��ֱ�ӱȽ���ֵ�Ĵ�С���ɡ�  
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