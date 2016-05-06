#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stdio.h>
#include <bitset>
#include <limits.h>
#include <memory>
#include <functional>
#include <sstream>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <bitset>
#include <list>
#include <fstream>
#include <boost/array.hpp>
#include <fstream>
#include <arpa/inet.h>

using namespace std;

struct ListNode {
    int value;
    ListNode * next;
    ListNode(int v): value(v), next(NULL) {}
};


ListNode * afl_add_two_number(ListNode* l1, ListNode* l2) {

    int v1(0), v2(0), count(0);
    ListNode * p = l1;

    while (p) {
        v1 += p->value * pow(10, count++);
        p = p->next;
    }

    count = 0;
    p = l2;

    while(p) {
        v2 += p->value * pow(10, count++);
        p = p->next;
    }

    v1 += v2;
    ListNode *ret = new ListNode(v1 % 10);
    v1 /= 10;

    ListNode *pl = ret;
    while (v1 > 0) {
        ListNode *elem = new ListNode(v1 % 10);
        v1 = v1/10;
        pl->next = elem;
        pl = pl->next;
    }

    return ret;
}

void afl_add_two_number_pre() {
    ListNode *v11 = new ListNode(2);
    ListNode *v12 = new ListNode(4);
    ListNode *v13 = new ListNode(6);
    ListNode *v14 = new ListNode(8);
    v14->next = v13;
    v13->next = v12;
    v12->next = v11;

    ListNode *v21 = new ListNode(1);
    ListNode *v22 = new ListNode(3);
    ListNode *v23 = new ListNode(5);
    ListNode *v24 = new ListNode(7);
    v24->next = v23;
    v23->next = v22;
    v22->next = v21;

    ListNode *p = v14;
    while(p) {
        cout << p->value;
        if (p->next) cout << " > ";
        p = p->next;
    }

    cout << endl;

    p = v24;
    while(p) {
        cout << p->value;
        if (p->next) cout << " > ";
        p = p->next;
    }
    cout << endl;

    ListNode * ret = afl_add_two_number(v14, v24);

    while (ret) {
        cout << ret->value;
        if (ret->next) cout << " > ";
        ret = ret->next;
    }
    cout << endl;
}

#include <string.h>
void test_size() {
  /*  A a1;
    B b1;*/
    int i = 3;

    cout << "size of int:" << sizeof(i) << endl;
    cout << "size of char:" << sizeof(char) << endl;
    cout << "size of bool:" << sizeof(bool) << endl;
    cout << "size of short:" << sizeof(short) << endl;
    cout << "size of short int:" << sizeof(short int) << endl;
    cout << "size of int point:" << sizeof(&i) << endl;
    cout << "size of size_t:" << sizeof(size_t) << endl;
    cout << "size of int32_t:" << sizeof(int32_t) << endl;
    cout << "size of int16_t:" << sizeof(int16_t) << endl;
    cout << "size of long:" << sizeof(long) << endl;
    cout << "size of long long:" << sizeof(long long) << endl;
    cout << "size of double:" << sizeof(double) << endl;
    cout << endl;
/*
    cout << "size of class A: " << sizeof(a1) << endl;
    cout << "size of class B: " << sizeof(b1) << endl;
    cout << endl;

    cout << "size of class E: " << sizeof(class E) << endl;
    cout << endl;

    cout << "size of class A1: " << sizeof(class A1) << endl;
    cout << "size of class B1: " << sizeof(class B1) << endl;
    cout << "size of class C1: " << sizeof(class C1) << endl;
    cout << "size of class D1: " << sizeof(class D1) << endl;
    */
}

vector<int> twosum_1(vector<int>& nums, int target) {
    vector<int> ret;

    size_t i(0), j(0);

    for (i = 0; i < nums.size(); ++i) {
        if (nums[i] > target) continue;

        for(j = i + 1; j < nums.size(); ++j) {
            if (nums[j] > target) continue;
            if ((nums[i] + nums[j]) == target) {
                ret.push_back(i+1);
                ret.push_back(j+1);
                break;
            }
        }
    }
    return ret;
}


vector<int> twosum(vector<int>& nums, int target) {
    vector<int> ret;
    unordered_map<int, int> remain;

    for (size_t i = 0; i < nums.size(); ++i) {
        int look_value = target - nums[i];
        if (remain.find(look_value) != remain.end()) {
            ret.push_back(remain[look_value] + 1);
            ret.push_back(i + 1);
            break;
        }
        remain.insert({nums[i], i});
    }
    return ret;
}

void twosum_pre() {
    vector<int> input{2, 3, 11, 7, 15, 20, 40, 55, 3, 6, 7, 10};
    vector<int> ret = twosum(input, 12);

    for(auto elem: ret) {
        cout << elem << endl;
    }
}

void afl_unorderedmap() {
    unordered_map<int, string> one_map{{20, "twenty"}, {30, "thirty"}};
    unordered_map<int, string> sec_map(one_map);
    one_map.insert(make_pair(0, "50"));
    one_map.insert({1, "100"});
    one_map.emplace(2, "200");
    one_map.emplace(make_pair(3, "300"));
    one_map[4] = "400";

    cout << one_map.size() << endl;
    cout << one_map.count(2) << endl;
    cout << one_map[2] << endl;

    unordered_map<int, string> third_map(one_map.begin(), one_map.end());

    for(auto& elem : one_map) {
        cout << elem.first << " : " << elem.second << endl;
    }

    cout << endl;
    for (auto& elem : sec_map) {
        cout << elem.first << " : " << elem.second << endl;
    }
    cout << endl;
    for(auto& elem : third_map) {
        cout << elem.first << " : " << elem.second << endl;
    }
    cout << "\n";

    for (size_t i = 0; i < third_map.size(); ++i) {
        cout << third_map[i] << endl;
    }
}

class __attribute__((__packed__)) A {
    public:
       int a;
       virtual void v() {};
};


class __attribute__((__packed__)) B: public A{
    public:
       int b;
       virtual void w() {};
};

class Base {
};

class Child: public Base {
};


void test_sizeof(){
    A* p = new A();
    cout << "sizeof B instance: " << sizeof(*p) << endl;
    A* pp = new B();
    cout << "sizeof pp instance: " << sizeof(*pp) << endl;

}

void test_reference() {
    int x = 0;
    int y = 3;
    int &r = x;
    cout << "r is refer to " << r << endl;
    r = y;

    x = 10;
    cout << "r is refer to " << r << endl;

    int *p = &x;
    int *p2 = &r;
    cout << ((p == p2)? "same address" : "different address") << endl;
}

void afl_swap(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

class __attribute__((__packed__)) Q {
public:
    int a;
    virtual void v();
};

class __attribute__((__packed__))  W {
public:
    int b;
    virtual void w();
};

class __attribute__((__packed__))  E :  public Q, public W {
public:
    int c;
    virtual void x();
};

vector<vector<int>> afl_find_three(vector<int> nums, int target, int level) {

    vector<vector<int>> ret;

    if(level == 1) {
        for (size_t k = 0; k < nums.size(); ++k) {
            if (nums[k] == target) {
                vector<int> m{nums[k]};
                ret.push_back(m);
            }
        }
    }
    else if (level > 1) {
        for (size_t i = 0; i < nums.size(); ++i) {
            int e = nums[i];
            vector<int> new_nums(nums.begin()+i+1, nums.end());
            vector<vector<int>> m = afl_find_three(new_nums, target - e, level-1);
            if (m.size() > 0) {
                for(auto elem : m) {
                    elem.push_back(nums[i]);
                    ret.push_back(elem);
                }
            }
        }
    }

    return ret;
}

vector<vector<int>> afl_find_three(vector<int> nums, int target) {
    vector<vector<int>> ret = afl_find_three(nums, target, 3);

    for (vector<int>& elem : ret ) {
        std::sort(elem.begin(), elem.end());
    }

    return ret;
//    ret.push_back({1, 2, 3});
//    ret.emplace(ret.begin(), vector<int>({10, 20, 30}));
}

void afl_find_three_pre() {
    vector<int> nums{-1, 2, 3, 0, 5, -3, 1, -2, 4};
    vector<vector<int>> d = afl_find_three(nums, 0);

    for (vector<int>& elem: d) {
        for (int i : elem) {
            cout << i << "  ";
        }
        cout << endl;

    }
}

void afl_longestP(string str) {
    int p[str.size()];
    *p = 10;

    int* s = new int[str.size()];
    s[1] = 10;

}


void afl_bool() {
    bool boolA[ 10 ] = { false }; //Like this.

	bool boolB[ 10 ];

	for( int i = 0; i < 10; ++i ) //Or loop the array and init them.
		boolB[ i ] = true;


	//Output the arrays...
	std::cout << "Bool A:\n";

	for( int i = 0; i < 10; ++i )
		std::cout << boolA[ i ] << '\n';

	std::cout << "Bool B:\n";

	for( int i = 0; i < 10; ++i )
		std::cout << boolB[ i ] << '\n';
}

int afl_p_f(int n, int k) {
    int d0 = 0, d = k, s = 0;

    for (int i = 2; i <=n; ++i) {
        int temp = d;
        d = (k-1) * (d0 + d);
        s = d0 = temp;
    }

    return d + s;
}

int afl_p_f_2(int n, int k) {
    if(n == 0) return 0;
    else if(n == 1) return k;

    int diffColorCounts = k*(k-1);
    int sameColorCounts = k;

    for(int i=2; i<n; i++) {
        int temp = diffColorCounts;
        diffColorCounts = (diffColorCounts + sameColorCounts) * (k-1);
        sameColorCounts = temp;
    }
    return diffColorCounts + sameColorCounts;
}


int afl_cost_min_1(vector<vector<int>> costs) {
    vector<int> d0{costs[0][0], costs[0][1], costs[0][2]};

    int n = costs.size();
    for (int i = 1; i < n; ++i) {
        d0[0] = min(d0[1], d0[2]) + costs[i][0];
        d0[1] = min(d0[0], d0[2]) + costs[i][1];
        d0[2] = min(d0[0], d0[1]) + costs[i][2];
    }

    return min(d0[0], min(d0[1], d0[2]));
}

int afl_number_square(int n) {
    vector<int> nums(n+1, INT_MAX);
    nums[0] = 0;
    nums[1] = 1;

    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j*j <= i; ++j) {
           nums[i] = min(nums[i], nums[i-j*j] + 1);
        }
    }

    for(int k : nums) {
        cout << k<< endl;
    }
    return nums.back();
}

void afl_smart_pointer() {
    unique_ptr<int> p{new int(7)};
    ++*p;
    cout << *p << endl;
}

void afl_print_num(int i) {
    cout << i << endl;
}


class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    bool operator == (const Complex& rhs) {
        return (real == rhs.real && imag == rhs.imag);
    }
};

class ComplexExt : public Complex {
};

void afl_lambda() {
    auto func = [] (const string& str) {return str.find("org")!=string::npos;};

    cout << func("tech.org") << endl;
    vector<int> v;

    v.push_back(1);
    v.push_back(2);

    for (auto itr = v.begin(), end = v.end(); itr != end; itr++) {
        cout << *itr << endl;
    }

    std::function<void(int)> f_display =  afl_print_num;
    f_display(10);

    std::function<void()> f_display_42 = []() {afl_print_num(42);};
    f_display_42();
}

void afl_removeduplicateletters1(string p) {
    cout << p << endl;

    std::sort(p.begin(),p.end());
    p.erase(std::unique(p.begin(), p.end()), p.end());

    for(auto l = p.begin(); l < p.end(); ++l) {
        cout << *l << endl;
    }

    string str("afl need testing need seeds");
    uint32_t pos = str.rfind("need");

    if (pos != string::npos) {
        str.replace(pos,str.size(),"kkk");
    }
    cout << str << endl;
}

void afl_removeduplicateletters(string p) {
    int k[256] = {};
    for(char a : p) {
        k[int(a)]++;
    }

    string result = "";
    bool inresult[256] = {};

    for(char a : p) {
        k[int(a)]--;
        if (inresult[int(a)]) continue;

        while (a < result.back() && k[int(result.back())]) {
            inresult[int(result.back())] =  false;
            result.pop_back();
        }

        result += a;
        inresult[int(a)] = true;
    }

    cout << result << endl;
}

void afl_simplypath(string p) {
    stringstream src(p);
    string token;
    vector<string> tokenList;

    while(getline(src, token, '/')) {
        tokenList.push_back(token);
    }

    cout << tokenList.size() << endl;
    for (auto e : tokenList) {
        cout << e << endl;
    }

    stack<string> path;
    for (uint i = 0; i < tokenList.size(); ++i) {
        if (tokenList[i] == "" || tokenList[i] == ".") continue;
        if (tokenList[i] == "..") {
            if (!path.empty()){
                path.pop();
            }
            else {
                perror("invalid error");
                return;
            }
        }
        else {
            path.push(tokenList[i]);
        }
    }

    string ret;
    while (!path.empty()) {
        string t = path.top();
        path.pop();
        ret = "/" + t + ret;
    }

    cout << ret << endl;
}

struct packet_msg_flag {
    union {
           struct {
               uint32_t
                         pmf_verdict_allow           :1,
                         pmf_verdict_drop            :1,
                         pmf_verdict_reject_src      :1,
                         pmf_verdict_reject_dst      :1;
                                                                                                       };
                                                                                                       uint32_t        value;
    };
} __attribute__((__packed__));

#define MAC_ADDR_LEN 30
#define WMAY_ALIAS __attribute__((__may_alias__))
#define WPACKED __attribute__((__packed__))

typedef struct WEthHdr_
{
    uint8_t     dst[30];
    uint8_t     src[30];
    uint16_t    type;
    uint8_t     payload[];
}WPACKED WMAY_ALIAS WEthHdr;

typedef struct VlanTag_ {
    uint16_t    tpid;  //tag protocol identifier
    uint16_t    tci;   //tag control information
}WPACKED WMAY_ALIAS  VlanTag;

typedef struct WVlanHdr_
{
    uint8_t     dst[MAC_ADDR_LEN];
    uint8_t     src[MAC_ADDR_LEN];
    VlanTag     c_tag;    //customer tag
    uint16_t    type;
    uint8_t     payload[];
}WPACKED WMAY_ALIAS  WVlanHdr;

typedef struct WDblTagVlanHdr_
{
    uint8_t     dst[MAC_ADDR_LEN];
    uint8_t     src[MAC_ADDR_LEN];
    VlanTag     s_tag;    //service  tag tpid 0x9100
    VlanTag     c_tag;    //customer tag tpid 0x8100
    uint16_t    type;
    uint8_t     payload[];
}WPACKED WMAY_ALIAS  WDblTagVlanHdr;

typedef union {
    WEthHdr         ethHdr;
    WVlanHdr        vlanHdr;
    WDblTagVlanHdr  dblTagVlanHdr;
} L2Hdr;

int main_union() {
    cout << sizeof(WEthHdr) << endl;
    cout << sizeof(WVlanHdr) << endl;
    cout << sizeof(WDblTagVlanHdr) << endl;
    cout << sizeof(L2Hdr) << endl;
    return 0;
}

class __attribute__((__packed__))  A1 {
    public:
        int a;
        virtual void f() {};
};

class __attribute__((__packed__))  B1:   virtual public A1{
    public:
        int b;
        virtual void e() {};
};

class __attribute__((__packed__))  B2:  virtual public A1{
    public:
        int b2;
        virtual void l() {};
};

class __attribute__((__packed__))  D1: public B1, public B2 {
public:
    int d;
    virtual void ee() {};
};

struct ListRNode {
    int value;
    ListRNode* next;
    ListRNode* random;
    ListRNode(): value(0), next(NULL), random(NULL) {}
    ListRNode(int v): value(v), next(NULL), random(NULL) {}
};

void ReverseList(ListRNode* head) {
    ListRNode* p = NULL;
    ListRNode* iter = head;

    while (iter) {
        ListRNode* next = iter->next;
        iter->next = p;
        p = iter;
        iter = next;
    }

    while(p) {
        cout << p->value << endl;
        p = p->next;
    }
}

ListRNode* MergeList(ListRNode* h, ListRNode* t) {
    ListRNode dummy(0);
    ListRNode* p = &dummy;

    while (h && t) {
        if (h->value < t->value) {
            p->next = h;
            h = h->next;
        }
        else {
            p->next = t;
            t = t->next;
        }
        p = p->next;
    }
    p->next = h?h:t;
    return dummy.next;
}

ListRNode* SortList(ListRNode* head) {
   if (head == NULL || head->next == NULL) return head;

   ListRNode* s = head;
   ListRNode* f = head->next->next;

   while(f && f->next) {
       s = s->next;
       f = f->next->next;
   }

   ListRNode* l = SortList(s->next);
   s->next = NULL;
   return MergeList(SortList(head), l);
}

bool CheckListCircle(ListRNode* head) {
    if (head == NULL || head->next == NULL) return false;

    ListRNode* s = head;
    ListRNode* f = head->next->next;
    while(s && f && f->next) {
        if (s == f) return true;
        s = s->next;
        f = f->next->next;
    }
    return false;
}

char* strstr(char* str, char* sub){
    char* iter, *a;
    if (sub == NULL || strlen(sub) == 0) return str;

    for (; *str != 0; str++) {
        if (*str != *sub) continue;

        iter = str;
        a = sub;
        while(1) {
            if (*a == 0) return str;
            else if (*a++ != *iter++) break;
        }
    }
    return 0;
}

void clonelist(ListRNode* head)
{
    map<ListRNode*, ListRNode*> map;

    ListRNode* iter = head;
    ListRNode dummy(0);
    ListRNode* newiter = &dummy;

    while (iter) {
       ListRNode* temp = iter->next;
       map.emplace(iter, temp);
       newiter->next = new ListRNode(iter->value);
       iter->next = newiter->next;
       newiter = newiter->next;
       newiter->random = iter;
       iter = temp;
    }

    newiter = dummy.next;
    while(newiter) {
        newiter->random = newiter->random->random->next;
        newiter = newiter->next;
    }

    iter = head;
    while(iter) {
        iter->next = map.find(iter)->second;
        iter = iter->next;
    }

    ListRNode* p = head;
    while(p) {
       // cout << p->value << endl;
        cout << p->random->value << endl;
        p = p->next;
    }
}

ListRNode* LinkList_pre(){
    ListRNode* n1 = new ListRNode(1);
    ListRNode* n2 = new ListRNode(9);
    ListRNode* n3 = new ListRNode(3);
    ListRNode* n4 = new ListRNode(4);
    ListRNode* n5 = new ListRNode(8);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    return n1;
}

char * strstr1(char* string, char* substring)
{
    register char *a, *b;

    /* First scan quickly through the two strings looking for a
     * single-character match.  When it's found, then compare the
     * rest of the substring.
     */

    b = substring;
    if (*b == 0) {
        return string;
    }
    for ( ; *string != 0; string += 1) {
        if (*string != *b) {
            continue;
        }
        a = string;
        while (1) {
            if (*b == 0) {
                return string;
            }
            if (*a++ != *b++) {
                break;
            }
        }
        b = substring;
    }
    return (char *) 0;
}

static int maxExponent = 511;	/* Largest possible base 10 exponent.  Any
				 * exponent larger than this will already
				 * produce underflow or overflow, so there's
				 * no need to worry about additional digits.
				 */
static double powersOf10[] = {	/* Table giving binary powers of 10.  Entry */
    10.,			/* is 10^2^i.  Used to convert decimal */
    100.,			/* exponents into floating-point numbers. */
    1.0e4,
    1.0e8,
    1.0e16,
    1.0e32,
    1.0e64,
    1.0e128,
    1.0e256
};

#include <ctype.h>

/*
 * The table below is used to convert from ASCII digits to a
 * numerical equivalent.  It maps from '0' through 'z' to integers
 * (100 for non-digit characters).
 */

static char cvtIn[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,		/* '0' - '9' */
    100, 100, 100, 100, 100, 100, 100,		/* punctuation */
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,	/* 'A' - 'Z' */
    20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 35,
    100, 100, 100, 100, 100, 100,		/* punctuation */
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,	/* 'a' - 'z' */
    20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 35};
double strtod(const char* string, char** endPtr)
    /* A decimal ASCII floating-point number,
				 * optionally preceded by white space.
				 * Must have form "-I.FE-X", where I is the
				 * integer part of the mantissa, F is the
				 * fractional part of the mantissa, and X
				 * is the exponent.  Either of the signs
				 * may be "+", "-", or omitted.  Either I
				 * or F may be omitted, or both.  The decimal
				 * point isn't necessary unless F is present.
				 * The "E" may actually be an "e".  E and X
				 * may both be omitted (but not just one).
				 */
    	/* If non-NULL, store terminating character's
				 * address here. */
{
    int sign, expSign = false;
    double fraction, dblExp, *d;
    register const char *p;
    register int c;
    int exp = 0;		/* Exponent read from "EX" field. */
    int fracExp = 0;		/* Exponent that derives from the fractional
				 * part.  Under normal circumstatnces, it is
				 * the negative of the number of digits in F.
				 * However, if I is very long, the last digits
				 * of I get dropped (otherwise a long I with a
				 * large negative exponent could cause an
				 * unnecessary overflow on I alone).  In this
				 * case, fracExp is incremented one for each
				 * dropped digit. */
    int mantSize;		/* Number of digits in mantissa. */
    int decPt;			/* Number of mantissa digits BEFORE decimal
				 * point. */
    const char *pExp;		/* Temporarily holds location of exponent
				 * in string. */

    /*
     * Strip off leading blanks and check for a sign.
     */

    p = string;
    while (isspace(*p)) {
	p += 1;
    }
    if (*p == '-') {
	sign = true;
	p += 1;
    } else {
	if (*p == '+') {
	    p += 1;
	}
	sign = false;
    }

    /*
     * Count the number of digits in the mantissa (including the decimal
     * point), and also locate the decimal point.
     */

    decPt = -1;
    for (mantSize = 0; ; mantSize += 1)
    {
	c = *p;
	if (!isdigit(c)) {
	    if ((c != '.') || (decPt >= 0)) {
		break;
	    }
	    decPt = mantSize;
	}
	p += 1;
    }

    /*
     * Now suck up the digits in the mantissa.  Use two integers to
     * collect 9 digits each (this is faster than using floating-point).
     * If the mantissa has more than 18 digits, ignore the extras, since
     * they can't affect the value anyway.
     */
    
    pExp  = p;
    p -= mantSize;
    if (decPt < 0) {
	decPt = mantSize;
    } else {
	mantSize -= 1;			/* One of the digits was the point. */
    }
    if (mantSize > 18) {
	fracExp = decPt - 18;
	mantSize = 18;
    } else {
	fracExp = decPt - mantSize;
    }
    if (mantSize == 0) {
	fraction = 0.0;
	p = string;
	goto done;
    } else {
	int frac1, frac2;
	frac1 = 0;
	for ( ; mantSize > 9; mantSize -= 1)
	{
	    c = *p;
	    p += 1;
	    if (c == '.') {
		c = *p;
		p += 1;
	    }
	    frac1 = 10*frac1 + (c - '0');
	}
	frac2 = 0;
	for (; mantSize > 0; mantSize -= 1)
	{
	    c = *p;
	    p += 1;
	    if (c == '.') {
		c = *p;
		p += 1;
	    }
	    frac2 = 10*frac2 + (c - '0');
	}
	fraction = (1.0e9 * frac1) + frac2;
    }

    /*
     * Skim off the exponent.
     */

    p = pExp;
    if ((*p == 'E') || (*p == 'e')) {
	p += 1;
	if (*p == '-') {
	    expSign = true;
	    p += 1;
	} else {
	    if (*p == '+') {
		p += 1;
	    }
	    expSign = false;
	}
	while (isdigit(*p)) {
	    exp = exp * 10 + (*p - '0');
	    p += 1;
	}
    }
    if (expSign) {
	exp = fracExp - exp;
    } else {
	exp = fracExp + exp;
    }

    /*
     * Generate a floating-point number that represents the exponent.
     * Do this by processing the exponent one bit at a time to combine
     * many powers of 2 of 10. Then combine the exponent with the
     * fraction.
     */
    
    if (exp < 0) {
	expSign = true;
	exp = -exp;
    } else {
	expSign = false;
    }
    if (exp > maxExponent) {
	exp = maxExponent;
    }
    dblExp = 1.0;
    for (d = powersOf10; exp != 0; exp >>= 1, d += 1) {
	if (exp & 01) {
	    dblExp *= *d;
	}
    }
    if (expSign) {
	fraction /= dblExp;
    } else {
	fraction *= dblExp;
    }

done:
    if (endPtr != NULL) {
	*endPtr = (char *) p;
    }

    if (sign) {
	return -fraction;
    }
    return fraction;
}

unsigned long int strtoul(char* string, char** endPtr, int base)
    	/* String of ASCII digits, possibly
				 * preceded by white space.  For bases
				 * greater than 10, either lower- or
				 * upper-case digits may be used.
				 */
    	/* Where to store address of terminating
				 * character, or NULL. */
    		/* Base for conversion.  Must be less
				 * than 37.  If 0, then the base is chosen
				 * from the leading characters of string:
				 * "0x" means hex, "0" means octal, anything
				 * else means decimal.
				 */
{
    register char *p;
    register unsigned long int result = 0;
    register unsigned digit;
    int anyDigits = 0;

    /*
     * Skip any leading blanks.
     */

    p = string;
    while (isspace(*p)) {
	p += 1;
    }

    /*
     * If no base was provided, pick one from the leading characters
     * of the string.
     */
    
    if (base == 0)
    {
	if (*p == '0') {
	    p += 1;
	    if (*p == 'x') {
		p += 1;
		base = 16;
	    } else {

		/*
		 * Must set anyDigits here, otherwise "0" produces a
		 * "no digits" error.
		 */

		anyDigits = 1;
		base = 8;
	    }
	}
	else base = 10;
    } else if (base == 16) {

	/*
	 * Skip a leading "0x" from hex numbers.
	 */

	if ((p[0] == '0') && (p[1] == 'x')) {
	    p += 2;
	}
    }

    /*
     * Sorry this code is so messy, but speed seems important.  Do
     * different things for base 8, 10, 16, and other.
     */

    if (base == 8) {
	for ( ; ; p += 1) {
	    digit = *p - '0';
	    if (digit > 7) {
		break;
	    }
	    result = (result << 3) + digit;
	    anyDigits = 1;
	}
    } else if (base == 10) {
	for ( ; ; p += 1) {
	    digit = *p - '0';
	    if (digit > 9) {
		break;
	    }
	    result = (10*result) + digit;
	    anyDigits = 1;
	}
    } else if (base == 16) {
	for ( ; ; p += 1) {
	    digit = *p - '0';
	    if (digit > ('z' - '0')) {
		break;
	    }
	    digit = cvtIn[digit];
	    if (digit > 15) {
		break;
	    }
	    result = (result << 4) + digit;
	    anyDigits = 1;
	}
    } else {
	for ( ; ; p += 1) {
	    digit = *p - '0';
	    if (digit > ('z' - '0')) {
		break;
	    }
	    digit = cvtIn[digit];
	    if (digit >= (unsigned int)base) {
		break;
	    }
	    result = result*base + digit;
	    anyDigits = 1;
	}
    }

    /*
     * See if there were any digits at all.
     */

    if (!anyDigits) {
	p = string;
    }

    if (endPtr != 0) {
	*endPtr = p;
    }

    return result;
}

void SetBit(int a[], int k) {
    a[k/32] |= (1 << k%32);
}

void ClearBit(int a[], int k) {
    a[k/32] &= ~(1 << k%32);
}

bool TestBit(int a[], int k) {
    return ((a[k/32] & (1<< k%32)) != 0);
}

void missingnumber(int* arri, int n, int k) { // missing k nums in the 1..n
    bool* b = (bool*) calloc(n,1);

    for (int i = 0; i < n-k; ++i) {
        b[arri[i]] = true;
    }

    for (int i = 0; i < n; ++i) {
        if (!b[i]) {
            cout << i << endl;
        }
    }
}

#include <assert.h>
/* replace the element with the element at the end of the array */
int RemoveElements1(int array[], int m, int index[], int n) {
    int newlen = m;
    std::sort(index, index + n);
    for (int i = n-1; i >= 0; --i) {
        if (index[i] >= m  || index[i] < 0) continue;
        array[index[i]] = array[newlen-1];
        newlen--;
    }

    for (int i = 0; i < m; ++i) {
        cout << array[i] << endl;
    }
    return newlen;
}

/* array is the integer array
   m is the length of the interger array
   index is the array of th index to be removed
   n is the length of the index array
   return is the new length of the integer array
*/

/*use memmove to override the element to be removed*/
int RemoveElements2(int array[], int m, int index[], int n) {
    assert(array);
    assert(index);

    set<int> s(index, index + n);
    for (auto e : s) {
        cout << e << endl;
    }

    cout << endl;
    int newlen = m;
    std::sort(index, index + n);
  //  int k = std::unique(index, index + n);

    for (int i = n-1; i >= 0; --i) {
        if (index[i] >= m  || index[i] < 0) continue;
        memmove(array+index[i], array+index[i]+1, (newlen-index[i]-1)*sizeof(int));
        newlen--;
    }
    for (int i = 0; i < m; ++i) {
        cout << array[i] << endl;
    }
    return newlen;
}


/* the elements in set is ordered from high to low */
struct setcomp {
  bool operator() (const int& lhs, const int& rhs) const {return lhs > rhs;}
};

/* array is the integer array
   m is the length of the interger array
   index is the array of th index to be removed
   n is the length of the index array
   return is the new length of the integer array
*/

/* use memmove to override the element to be removed
   this method will just remove the element, but keep the original order
*/
int RemoveElements(int array[], int m, int index[], int n) {
    assert(array);
    assert(index);

    int newlen = m;
    set<int, setcomp> s(index, index + n);
    for (auto& e : s) {
        if (e >= m  || e < 0) continue;
        memmove(array + e, array + e + 1, (newlen - e - 1)*sizeof(int));
        newlen--;
    }

    return newlen;
}

/* replace the element with the element at the end of the array
   this method will remove the element and also change the original order
*/
int RemoveElements_sec(int array[], int m, int index[], int n) {
    assert(array);
    assert(index);

    int newlen = m;
    set<int, setcomp> s(index, index + n);
    for (auto& e : s) {
        if (e >= m  || e < 0) continue;
        array[e] = array[newlen-1];
        newlen--;
    }

    return newlen;
}

/*  in m + n -2 array, there will be m-1 0
    and n-1 1 find all the combination 
*/
int findpath(int m, int n) {
    if (m == 0 || n == 0) return 1;
    
    return findpath(m-1,n) + findpath(m, n-1);
}

vector<vector<int>> twosum2(vector<int> a, int k) {
    vector<vector<int>> ret;
    sort(a.begin(), a.end());
    int n = a.size();
    int l = 0, r = n - 1;

    while(l < r) {
        if (a[l] + a[r] == k) {
            ret.push_back({a[l], a[r]});
            l++;
            r--;
        }
        else if (a[l] + a[r] < k) {
            l++;
        }
        else {
            r--;
        }
    }

    for (auto& e : ret) {
        for (auto& i : e) {
            cout << i << " ";
        }
        cout << endl;
    }
    return ret;
}

void countduplicate(int a[], int n) {
   unordered_map<int, int> count;
   for(int i = 0; i < n; ++i) {
       count[a[i]]++;
   }

   int sum = 0;
   for (auto& e : count) {
       sum += (e.second - 1);
       printf("Key pair is %d::%d\n", e.first, e.second);
   }

   cout << sum << endl;
}

void removeduplicate(int a[], int n) {
    unordered_set<int> t;
    for(int i = 0; i < n; ++i) {
        t.emplace(a[i]);
    }

    for(auto& e : t) {
        cout << e<< endl;
    }
}

void countduplicate(vector<int> a) {
    sort(a.begin(), a.end());
    int k = std::distance(a.begin(), unique(a.begin(), a.end()));
    cout << a.size() - k;
}

/*
    for( int i = sizeof(value)*CHAR_BIT-1; i>=0; --i)
    cout << value & (1 << i) ? '1' : '0';
    
    bitset< sizeof(value)*CHAR_BIT > bits( value );
    cout << bits.to_string();
*/
void convertdecimaltobinary() {
    bitset<sizeof(int)*CHAR_BIT> bits(100);
    cout << bits.to_string() << endl;

    bitset<32> b(200);
    cout << b.to_ulong() << endl;
}

void convertdecialtohex() {
    unsigned int i = 0x64;
    char p[100];

    snprintf(p, 100, "%d", i);
    unsigned int k = atoi(p);
    printf("%d\n", k);
}

class Base11 {
private:
int x;
public:
virtual void mf1() = 0;
virtual void mf1(int) {cout << "Base::mf1(int)" << endl;}
virtual void mf2() {}
void mf3() {cout << "BASE::mf3()" << endl;}
void mf3(double) {cout << "BASE::mf3(double)" << endl;}
};

void Base11::mf1() {
    cout << "Base::mf1()" << endl;
}

class Derived11: public Base11 {
public:
//using Base11::mf1;
//using Base11::mf3;
virtual void mf1() {cout << "Derived::mf1()" << endl;}
void mf2() {cout << "Derived::mf2()" << endl;}
void mf3() {cout << "Derived::mf3()" << endl;}
void mf4() {cout << "Derived::mf4()" << endl;}
};


class Grandparent {
public:
    Grandparent() { cout << "default construct is called" << endl;}
    Grandparent(const Grandparent& obj)  {cout << "Grandparent copy const called" << endl;}
    Grandparent& operator=(const Grandparent& obj);
    virtual void f() {cout << "Grandparent::f" << endl;}
};

Grandparent& Grandparent::operator=(const Grandparent& obj) {
    cout << "Grandparent operation = is called" << endl;
    return *this;
}

class Parent : public Grandparent {
public:
    void f() {cout << "Parent::f" << endl;}
};

class Child1 : public Parent {
public:
    void f() {cout << "Child::f" << endl;}
};

struct TT {
    virtual int foo() {return 0;}
};


void aflmissingnum (int* data, int n, bool* extra, int k)
{
    // data contains n distinct numbers from 1 to n + k, extra provides
    // space for k extra bits. 

    // Rearrange the array so there are (even) even numbers at the start
    // and (odd) odd numbers at the end.
    int even = 0, odd = 0;
    while (even + odd < n)
    {
        if (data [even] % 2 == 0) ++even;
        else if (data [n - 1 - odd] % 2 == 1) ++odd;
        else { int tmp = data [even]; data [even] = data [n - 1 - odd]; 
               data [n - 1 - odd] = tmp; ++even; ++odd; }
    }

    // Erase the lowest bits of all numbers and set the extra bits to 0.
    for (int i = even; i < n; ++i) data [i] -= 1;
    for (int i = 0; i < k; ++i) extra [i] = false;

    // Set a bit for every number that is present
    for (int i = 0; i < n; ++i)
    {
        int tmp = data [i];
        tmp -= (tmp % 2);
        if (i >= odd) ++tmp;
        if (tmp <= n) data [tmp - 1] += 1; else extra [tmp - n - 1] = true;
    }

    // Print out the missing ones
    for (int i = 1; i <= n; ++i)
        if (data [i - 1] % 2 == 0) printf ("Number %d is missing\n", i);
    for (int i = n + 1; i <= n + k; ++i)
        if (! extra [i - n - 1]) printf ("Number %d is missing\n", i);

    // Restore the lowest bits again.
    for (int i = even; i < n; ++i) data[i] += 1;
}


struct Data {
    Data(string k, uint32_t v) : name(k), value(v) {}
    string name ;
    uint32_t value;
};

typedef unordered_map<string, list<Data>::iterator> CMAP;
typedef unordered_map<string, list<Data>::iterator>::iterator CMAPL;

class Cache {
public:
    Cache(int b, int c) : buffer_s(b), cache_s(c) {}
    int RetrieveRecent();
    int Retrieve(string key);
    void Delete(string key);
    void Add(string key, uint32_t value);
    void PrintOut();

private:
    int buffer_s;
    int cache_s;
    list<Data> buffer;
    CMAP sp;
};

void Cache::PrintOut() {
    for (auto& e : buffer) {
        cout << e.name << " :: " << e.value << endl;
    }

    cout << endl;
    for (auto& e : sp) {
        cout << e.first  << endl;
        cout << e.second->value << endl;
    }
}

int Cache::RetrieveRecent() {
    if (buffer.size() == 0) return -1;

    return buffer.back().value;
}

int Cache::Retrieve(string key) {
    uint32_t ret = -1;
    CMAPL lt = sp.find(key);
    if (lt != sp.end()) {
        ret = lt->second->value;
        this->Delete(key);
        this->Add(key, ret);
    }
    return ret;
}

void Cache::Delete(string key) {
    CMAPL lt = sp.find(key);
    if (lt != sp.end()) {
        buffer.erase(lt->second);
        sp.erase(lt);
    }
}

void Cache::Add(string key, uint32_t value) {
    CMAPL lt = sp.find(key);
    if (lt != sp.end()) {
        lt->second->value = value;
    }
    else {
        buffer.push_back(Data(key, value));
        list<Data>::iterator p = buffer.end();
        p--;
        sp.emplace(key, p);
        //sp.insert({key, p});
    }
}


/*
C version

    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("/etc/motd", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
    }

    fclose(fp);
    if (line)
        free(line);

C++ version
#include <sstream>
#include <string>
#include <fstream>

std::ifstream infile("thefile.txt");
std::string line;
while (std::getline(infile, line))
{
    std::istringstream iss(line);
    int a, b;
    if (!(iss >> a >> b)) { break; } // error

    // process pair (a,b)
}
*/

int file_read_write_main()
{
    vector<string> buffer;
    ifstream fp("word.txt");
    ofstream op("output.txt", ofstream::app);
    string line;

    while (getline(fp, line)) {
        buffer.emplace_back(line);
    }

    for (int n = 0; n < 100; ++n) {
        for (string str :  buffer) {
            op << str << endl;
        }
    }
    fp.close();
    op.close();

    ifstream dd("output.txt");
    vector<string> out_buf;
    while(getline(dd, line)) {
        out_buf.emplace_back(line);
    }
    cout << out_buf.size() << endl;
    dd.close();
    return 0;
}

void afl_process_string_concat(vector<string>& words)
{

}

int main()
{
    vector<string> words;
    string file_name = "word.txt";
    ifstream ifp(file_name.c_str());

    if (!ifp.is_open()) {
        exit(EXIT_FAILURE);
    }

    string line;
    while (ifp.good()) {
        getline(ifp, line);
        words.emplace_back(line);
    }

    ifp.close();
    afl_process_string_concat(words);
}

bool afl_one_letter_diff(string src, string dst)
{
   if (src.size() != dst.size()) return false;

   int count = 0;
   for (size_t i = 0; i < src.size(); ++i) {
       if (src[i] != dst[i]) count++;
   }

   return (count == 1);
}

int afl_ladder_length(unordered_set<string>& from, unordered_set<string>& to,
                      unordered_set<string>& dict, int level)
{
    if (from.size() == 0) return 0;

    unordered_set<string> new_from;
    for (string src : from) {
        for (string dst : to) {
            if (afl_one_letter_diff(src, dst))
                return level+1;
        }

        for (string dic : dict) {
            if (afl_one_letter_diff(src, dic)) {
                new_from.emplace(dic);
                dict.erase(dic);
            }
        }
    }
    return afl_ladder_length(new_from, to, dict, level+1);
}

int afl_main(string beginWord, string endWord, unordered_set<string> &dict) {
    unordered_set<string> from, to;

    if (beginWord == endWord) return 1;
    if (dict.size() == 0) return 0;

    from.emplace(beginWord);
    to.emplace(endWord);
    dict.erase(beginWord);
    dict.erase(endWord);
    return afl_ladder_length(from, to, dict, 0);
}
int ladderLengthHelper(std::unordered_set<std::string> &words1,
                       std::unordered_set<std::string> &words2,
                       std::unordered_set<std::string> &dict,
                       int level)
{
    if (words1.empty())
        return 0;
    if (words1.size() > words2.size())
        return ladderLengthHelper(words2, words1, dict, level);

    std::unordered_set<std::string> words3;
    for (auto it = words1.begin(); it != words1.end(); ++it) {
        std::string word = *it;
        for (auto ch = word.begin(); ch != word.end(); ++ch) {
            char tmp = *ch;
            for (*ch = 'a'; *ch <= 'z'; ++(*ch))
                if (*ch != tmp) {
                    if (words2.find(word) != words2.end())
                        return level + 1;
                    else if (dict.find(word) != dict.end()) {
                        dict.erase(word);
                        words3.insert(word);
                    }
                }
            *ch = tmp;
        }
    }
    return ladderLengthHelper(words2, words3, dict, level + 1);
}

int ladderLength(std::string beginWord,
                 std::string endWord,
                 std::unordered_set<std::string> &dict)
{
    if (beginWord == endWord)
        return 1;
    std::unordered_set<std::string> words1, words2;
    words1.insert(beginWord);
    words2.insert(endWord);
    dict.erase(beginWord);
    dict.erase(endWord);
    return ladderLengthHelper(words1, words2, dict, 1);
}

int afl_string_reverse()
{
    unsigned char k = 250;
    printf("%u\n", k);

    char *str = (char*)calloc(1, 100);
    strcat(str, "afl reverse string testing");
    size_t s = 0, e = strlen(str)-1;

    while (s < e) {
       str[s] ^= str[e];
       str[e] ^= str[s];
       str[s++] ^= str[e--];
    }

    cout << str << endl;
    return 0;
}
void afl_spiral(vector<vector<int>> matrix) {
}

void ReverseString(string& intext, int lindex, int rindex)
{
    char tempc;
    while (lindex < rindex)
    {
        tempc = intext[lindex];
        intext[lindex++] = intext[rindex];
        intext[rindex--] = tempc;
    }
}

void ReverseAllWords2(string& str) {
    std::reverse(str.begin(), str.end());
    size_t l = 0, r = 0;

    for (; r <= str.size(); ++r) {
        if (r == str.size() || str[r] == ' ') {
            std::reverse(str.begin()+l, str.begin()+r);
            l = r+1;
        }
    }
}

string ReverseAllWords(string& in_text)
{
    int lindex = 0;
    int rindex = in_text.size() - 1;
    if (rindex > 1)
    {
        //reverse complete phrase
        ReverseString(in_text, 0, rindex);

        //reverse each word in resultant reversed phrase
        for (rindex = 0; rindex <= (int)in_text.size(); rindex++)
        {
            if (rindex == (int)in_text.size() || in_text[rindex] == ' ')
            {
                ReverseString(in_text, lindex, rindex - 1);
                lindex = rindex + 1;
            }
        }
    }
    return in_text;
}

struct Base1
{
private:
    void foo(float);
};

struct Derived1: public Base1
{
public:
    void foo(int);
};

int main_1() {
    string s = "  afl probably   run in parrallel   ";
    ReverseAllWords2(s);
    cout << s << endl;
    return 0;

}

struct ppdf {
    int fd;
    short event;
    short message;
};

int main2() {

    uint32_t k = 32342;
    bitset<32> a(k);
    cout << a.count() << endl;
    cout << a.set(2) << '\n';

    cout << endl;

    ppdf p = {.fd = 10, .event = 33, .message = 2};
    cout << p.fd << "::" << p.message << endl;
    return 0;
}

int main1() {
//    ListRNode* head = LinkList_pre();
    int a[10] = {1,2,3};
    int b[5] = {20, 30};


    for(int i = 0; i < 10; ++i) {
        cout << a[i] << endl;
    }

    cout << endl;
    for (int i = 0; i < 5; ++i) {
        cout << b[i] << endl;
    }

    cout << "sizeof(b) is " << sizeof(b) << endl;
    memcpy(a+2, a, 3*sizeof(int));

    for(int i = 0; i < 10; ++i) {
        cout << a[i] << endl;
    }

    cout << endl;

    void * node = new ListRNode;
    printf("size of node is %d\n", (int)sizeof(node));

    ListRNode nodes[5];
    nodes[2].value = 10;

    printf("size of the node is %d\n", (int)sizeof(nodes[2]));
    printf("size of nodes is %d\n", (int)sizeof(nodes));
    memset(nodes, 0, sizeof(nodes));
    printf("nodes[2] value is %d\n", nodes[2].value);

    int ar[10] = {};
    for (int i = 0; i < 10; ++i){
        printf("ar[8] is %d\n", ar[i]);
    }
    printf("strstr string is %s\n", strstr("this is a sample tesing", "sample"));

    cout << sizeof(bool) << endl;

    return 0;
}


bool stringCompare(const string & l, const string & r)
{
   return (l==r);
}

int main_remove_duplicate()
{
  list<string> myStrings;
  myStrings.push_back("1001");
  myStrings.push_back("1001");
  myStrings.push_back("81");
  myStrings.push_back("1001");
  myStrings.push_back("81");

  myStrings.sort();
  myStrings.erase(unique(myStrings.begin(), myStrings.end(), stringCompare), myStrings.end());
  //myStrings.unique();

  list<string>::iterator it;
  for(it = myStrings.begin(); it != myStrings.end(); ++it)
  {
    cout << *it << endl;
  }

  return 0;
}

void PrintPatternRecursive(string str, int open, int close, int n) {
    if (open == n && close == n) {
        cout << str << endl;
        return;
    }
    if (open < n) {
        PrintPatternRecursive(str+"(", open+1, close, n);
    }

    if (close < open) {
        PrintPatternRecursive(str+")", open, close+1, n);
    }
}

void PrintPattern(int n) {
    PrintPatternRecursive("", 0, 0, n);
}

void InsertStack(stack<int>& src, int a) {
    if (src.empty() || src.top() <= a) {
        src.push(a);
        return;
    }

    int t = src.top();
    src.pop();
    InsertStack(src, a);
    src.push(t);
}

void SortStack(stack<int>& src) {
    if (src.empty()) return;

    int t = src.top();
    src.pop();
    SortStack(src);
    InsertStack(src, t);
}


string ShortPanlidom(string s) {
    string ret;

    return ret;
}

/*
C  67/43 0011 1
G  71/47 0111 3
A  65/41 0001 0
T  84/54 0100 2
*/
void convertDNA(string s) {
    char n = 0;
    for (auto e : s) {
        n = (n<<2)|((e&0x7)>>1);
    }
    cout << bitset<8>(n) << endl;
}

/*
If car starts at A and can not reach B. Any station between A and B can not reach B.(B is the first station that A can not reach.)
If the total number of gas is bigger than the total number of cost. There must be a solution.

Proof to the first point: say there is a point C between A and B -- that is A can reach C but cannot reach B. Since A cannot reach B, the gas collected between A and B is short of the cost. Starting from A, at the time when the car reaches C, it brings in gas >= 0, and the car still cannot reach B. Thus if the car just starts from C, it definitely cannot reach B.

Proof for the second point:

If there is only one gas station, it’s true.
If there are two gas stations a and b, and gas(a) cannot afford cost(a), i.e., gas(a) < cost(a), then gas(b) must be greater than cost(b), i.e., gas(b) > cost(b), since gas(a) + gas(b) > cost(a) + cost(b); so there must be a way too.
If there are three gas stations a, b, and c, where gas(a) < cost(a), i.e., we cannot travel from a to b directly, then:
either if gas(b) < cost(b), i.e., we cannot travel from b to c directly, then cost(c) > cost(c), so we can start at c and travel to a; since gas(b) < cost(b), gas(c) + gas(a) must be greater than cost(c) + cost(a), so we can continue traveling from a to b. Key Point: this can be considered as there is one station at c’ with gas(c’) = gas(c) + gas(a) and the cost from c’ to b is cost(c’) = cost(c) + cost(a), and the problem reduces to a problem with two stations. This in turn becomes the problem with two stations above.
or if gas(b) >= cost(b), we can travel from b to c directly. Similar to the case above, this problem can reduce to a problem with two stations b’ and a, where gas(b’) = gas(b) + gas(c) and cost(b’) = cost(b) + cost(c). Since gas(a) < cost(a), gas(b’) must be greater than cost(b’), so it’s solved too.
For problems with more stations, we can reduce them in a similar way. In fact, as seen above for the example of three stations, the problem of two stations can also reduce to the initial problem with one station.
*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start(0),total(0),tank(0);
    //if car fails at 'start', record the next station
    for(size_t i=0;i<gas.size();i++)
        if((tank=tank+gas[i]-cost[i])<0) {
            start=i+1;total+=tank;tank=0;
        }
    return (total+tank<0)? -1:start;
}
void CombineSequence(int n, vector<int>& arr, int cur, int index) {

   if (cur == n) {
       for (int i = 0; i < index; ++i) {
           cout << arr[i] << " ";
       }
       cout << endl;
       return;
   }

   int num = 1;
   while ((cur+num)<=n &&(index==0 || num<=arr[index-1])) {
       arr[index] = num;
       CombineSequence(n, arr, cur+num, index+1);
       num++;
   }
}

int CombineSequence_main() {
    int n = 5;
    vector<int> s(n, 0);
    CombineSequence(n, s, 0, 0);
    return 0;
}

int SortStack_m() {
    deque<int> t{10,3,9,23,-10,0,333,2};
    stack<int> a(t);
    SortStack(a);

    while (!a.empty()) {
        cout << a.top() << " ";
        a.pop();
    }
    return 0;
}

vector<int> BitCount1(int n) {
    vector<int> ret(n+1);
    ret[0] = 0;
    ret[1] = 1;

    int k = 1;
    for (int i = 2; i <=n; ++i) {
        if (i == 2*k) {
            k = i;
            ret[i] = 1;
        }
        else {
            ret[i] = ret[k] + ret[i-k];
        }
    }

    return ret;
}

int BitCount(unsigned int n) {
    int count = 0;
    while(n>0) {
        if (n&1) count++;
        n >>=1;
    }

    return count;
}
enum dhcp_type {
    dhcp_request,
    dhcp_response
};


struct __attribute__((__packed__)) dhcp_stru {
    uint8_t type;
    uint16_t code;
};

struct __attribute__((__packed__)) packed_struct {
//struct packed_struct {
   uint8_t f1:1;
   uint8_t f2:1;
   uint8_t f3:1;
   uint8_t f4:1;
   uint8_t type:4;
   uint32_t my_int:7;
};

int afl_strtok() {
    dhcp_stru jj;
    jj. type = 1;

    if (jj.type == dhcp_type::dhcp_request) {
        cout << "type matched" << endl;
    }
    else {
        cout << "type not matched" << endl;
    }

    char str[80] = "This is - www.tutorialspoint.com - website";
   const char s[2] = "-";
   char *token;
   
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) 
   {
      printf( " %s\n", token );
    
      token = strtok(NULL, s);
   }

   cout << sizeof(struct packed_struct) << endl;
    return 0;
}

int MyStrstr(string src, string needle) {
    size_t r = 0;
    vector<int> pos;
    for (size_t i = 0; i < src.size(); ++i) {
        if (needle[0] == src[i]) {
            pos.push_back(i);
        }
    }

    for (int e : pos) {
        while (src[e] == needle[r]) {
            e++;
            r++;
        }

        if (r == needle.size()) return e - needle.size();
    }
    return -1;
}

void readInput() {
    ifstream myReadFile;
    myReadFile.open("text.txt");
    string output;

    ofstream outputFile;
    outputFile.open("output.txt", ofstream::app);

    while (!myReadFile.eof()) {
        myReadFile >> output;
        outputFile.write(output.c_str(),(long)output.size());
        cout << output << endl;
    }

    outputFile.close();
    myReadFile.close();
}

/*
Given N activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

Note : The start time and end time of two activities may coincide.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. First line is N number of activities then second line contains N numbers which are starting time of activies.Third line contains N finishing time of activities.
 
Output:
For each test case, output a single number denoting maximum activites which can be performed in new line.
 

Constraints:
1<=T<=50
1<=N<=1000
1<=A[i]<=100
 

Example:
Input:
1
6
1 3 0 5 8 5
2 4 6 7 9 9

Output:
4
*/

