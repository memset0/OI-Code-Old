#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct Stick {
    int a[maxn], l;
    inline void clean() {l = 0;}
    inline void push(int x) {a[++l] = x;}
    inline int front() {return a[l];}
    inline int pop() {return a[l--];}
    inline int size() {return l;}
} f; //ջ 
map < string, int > a; //ԭ��=>��Ӧ��Է������� 
int n, t, i, j, len, ans, vint, vlen, vcnt;
bool unknown_mark; //�Ƿ��ҵ��˲����ڵ� 
string s, vname;
int main() {
    ios::sync_with_stdio(0); //��ͬ 
    while (1) {
        cin >> s;
        if (s == "END_OF_FIRST_PART") break;
        cin >> t, a[s] = t;
    }
    while(1) {
        cin >> s, len = s.length(); //���� 
        f.clean(), i = 0, unknown_mark = false; //���� 
        if (s == "0") break; //����������� 
        while (i < len) {
            if (isdigit(s[i])) {
                vint = 0;
                while (isdigit(s[i])) vint = vint * 10 + s[i] - '0', i++;
                f.push(f.pop() * vint);
            } else if (isupper(s[i])) {
                vname = s[i++];
                while (islower(s[i])) vname += s[i], i++;
                if (a[vname]) f.push(a[vname]);
                else {
                    unknown_mark = true;
                    break;
                }
            } else if (s[i] == '(') {
                f.push(-1), i++;
            } else if (s[i] == ')') {
                vcnt = 0;
                while (f.front() != -1) vcnt += f.pop();
                f.pop(), f.push(vcnt), i++;
            }
        }
        if (unknown_mark) cout << "UNKNOWN\n";
        else {
            ans = 0;
            while (f.size()) ans += f.pop();
            cout << ans << endl;
        }
    }
    return 0;
}

