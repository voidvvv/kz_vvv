#include "kmp.h"


int startOf (std::string &s, std::string &p) {
    int n = s.size();
    int m = p.size();
    if (n < m) return -1;
    std::vector<int> next = getNext(p);
    int sCur = 0;
    int pCur = 0;
    while (sCur < n && pCur < m) {
        if (s[sCur] == p[pCur]) {
            sCur++;
            pCur++;
        } else if (pCur > 0) {
            pCur = next[pCur - 1];
        } else {
            sCur++;
        }
    }

    return pCur == m ? sCur - m : -1;
}

std::vector<int> getNext (std::string &p) {
    std::vector<int> ans = std::vector<int>(p.size(), 0);
    int comp = 0; int cur = 2;
    while (cur < p.size()) {
        if (p[cur - 1] == p [comp]) {
            (ans)[cur - 1] = comp + 1;
            comp++;
            cur++;
        } else if (comp > 0) {
            comp = (ans)[comp - 1];
        } else {
            (ans)[cur - 1] = 0;
            cur++;
        }
    }
    return ans;
}
