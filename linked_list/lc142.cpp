#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *detectCycle(ListNode *head) {
    if (head == nullptr|| head->next == nullptr){
        return nullptr;
    }
    ListNode *pt1, *pt2;
    pt1 = head;
    pt2 = head;
    while (pt1 != nullptr && pt1->next != nullptr){
        pt1 = pt1->next->next;
        pt2 = pt2->next;
        if (pt1==pt2){break;}
    }
    if (pt1==nullptr||pt1->next==nullptr){return nullptr;}
    pt1 = head;
    while (pt1!= pt2){
        pt1 = pt1->next;
        pt2 = pt2->next;
    }
    return pt1;
}

int main(void){
    ListNode* l1 = new ListNode();
    ListNode* dummy1 = l1;
    ListNode* dummy2 = l1;
    vector<int> list1 = {7032,15013,6890,11344,320,13037,9414,6817,1566,14907,-2756,9931,-4488,11602,4887,1239,6231,-5366,8501,1142,-1367,-4140,-5460,15554,-4686,12603,1471,5378,15246,11273,13817,5814,3846,12556,1024,3348,13880,14906,14002,9863,8177,-2043,15882,11985,13339,4277,-2059,581,2628,5101,6794,4636,9550,-6947,-5352,1854,3064,5149,-5342,-7716,5203,3842,6401,6644,3565,15758,-1451,4993,13767,7789,9944,5132,-3127,-5734,2149,5437,3967,12988,-5397,8306,-4744,-6542,6952,6653,-7588,-345,7975,-1608,-4125,-108,5960,-56,3410,9927,-7835,-2576,-1390,1154,13654,-6793,14489,14739,15465,12843,14656,9998,-4416,10104,4804,1556,9350,5791,8999,-4762,12242,13264,-7520,10069,4058,-2512,15701,2663,-2845,13834,-7731,2176,6491,16008,10067,1898,15861,9934,10788,3358,6423,-7036,10398,-1460,594,-573,-3391,-3095,-3940,9549,13679,-3841,9564,-4596,10625,8753,-4429,-4085,1421,7715,-3544,6997,5974,6788,7438,7242,2765,10202,13904,-2925,11692,-2441,3938,14650,-2896,-5260,4662,10609,7075,-2022,15907,464,2044,14045,12870,-2546,-4893,13733,13590,14697,-7190,15540,569,10869,15050,-7747,7707,-6871,7459,6402,9260,-6298,1793,10826,9959,2771,-4703,13906,14181,-4960,-2680,-507,7196,15828,-4096,14023,-3265,-4492,12808,-258,11700,-4667,4321,13382,-2940,180,14907,-424,-3093,1215,13189,14936,6161,-1730,6783,1775,9164,-3637,-4981,11420,-5504,13435,-2134,13739,2382,3423,8390,-2107,4178,1808,-387,-4254,667,-973,7616,-6542,6263,10049,-2974,-5952,1479,15631,5470,2588,9579,6108,11561,1425,-6071,5259,4881,11130,15191,3066,6021,7378,-3866,6955,11761,-7086,14383,-7788,15588,-5370,-7198,-3040,1594,8564,5000,11453,10854,1735,15528,13504,4656,10885,10600,3781,11522,12687,9369,259,6835,13900,15690,-4397,6554,583,5555,1544,-6104,5930,4865,-1092,5856,7881,14355,15362,6095,9197,5905,-1736,-7548,15965,10400,2607,-2405,11548,11811,9387,6688,5716,12586,-897,-7593,8834,14696,668,3667,1063,-320,11893,9511,15182,9847,886,8508,-621,-7058,-6554,7779,-3182,3110,14239,7495,3321,3775,10645,-6678,358,1314,10553,7128,277,-1761,-5881,-1190,1912,1987,9058,12597,-7272,9278,7344,-5102,-7637,8801,12405,10816,14672,-1213,-1503,15660,14438,80,7149,-521,-1271,15834,-1456,4490,-588,3291,-1050,-1355,5505,1894,-5996,9716,13403,13135,-1149,4619,-2892,-6492,5752,-2252,-2381,2737,-3156,8401,3737,-6200,-6317,9853,-5430,-2323,14840,98,-3075,8473,-7191,1668,-6515,11492,2692,10903,2177,9093,13891,4648,5719,6209,-387,6609,3886,12638,-6936,12750,3462,14947,-1779,6423,-4305,-1096,-6136,10748,3097,3123,-4575,14325,5639,2898,6758,-1609,-7131,15483,8956,4284,3,-4744,15047,-6248,14096,12473,7661,1676,1011,-7016,-3620,-2627,3463,2012,6899,7050,1087,5070,-1869,8032,-253,11942,1700,-943,1336,3647,9608,13003,9566,1544,7851,-2480,-2597,-413,-1285,15651,9040,7423,2318,8365,762,8463,-81,-1664,11421,9250,-6386,8673,2172,1700,-539,5525,2190,-5696,8021,6499,2539,1803,15442,3181,7661,9269,1921,-1381,-6728,1031,-2056,-7001,1911,10050,7552,10873,15603,-4489,9096,2946,688,-4814,-6338,5387,-3490,-4096,13287,-733,4524,9540,3119,-5535,8398,8905,6603,3182,12521,2590,2351,9181,-7750,-7917,8258,-7843,2127,2641,-5464,9111,14987,-4995,-2476,9175,15247,12566,-1091,8199,-2632,-3310,14244,-6736,-3350,12761,-5108,7886,612,-4078,951,9049,-5646,13100,5665,-1463,15311,-1971,-4359,7707,6418,12968,9069,8523,4413,4573,5212,7233,-3245,-2653,-979,-7419,-336,8608,-1137,15442,11097,-5408,7207,9126,8702,8043,9261,4939,12841,-1369,2433,14381,9192,14239,15544,3077,-1056,-5565,14900,8747,2970,3187,13304,10173,5048,12127,5276,960,12910,4482,-7767,15219,4407,4121,12408,-3473,15187,-4177,1530,1019,706,3592,-934,8538,-7422,9169,-4861,2513,72,-760,-7794,-4267,14775,-5279,9024,248,5187,11962,10602,6297,13704,13940,-1076,4684,-6916,14347,-5737,-5480,3085,15171,-1009,5425,13310,6540,-4022,-5110,-61,-1710,-4470,-3722,7192,8016,-3485,-5251,-2986,11626,-4847,15782,6560,-331,1126,-3068,-1622,12133,12912,7326,7182,10535,-2671,6605,7126,1569,-6421,9763,-4028,-5209,-2777,-89,9841,932,-7642,9941,10136,11877,-4705,14881,-5262,746,314,3268,-740,-5276,14313,11533,10440,15136,-404,-160,7055,4898,4101,9264,-453,11885,260,-979,1989,6581,14864,12119,12382,3182,10638,2382,13449,3430,7888,585}; 
    for (int i=0;i<list1.size();i++){
        dummy1->next = new ListNode(list1[i]);
        dummy1 = dummy1->next;
    }
    l1 = l1->next;
    ListNode* result = detectCycle(l1);
    if (result != nullptr){
        cout << result->val;
    }
}