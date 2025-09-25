#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        //輸入測資
       int N , P; // N=模擬天數 P=有幾個罷工團體
       cin >> N >> P;
       vector<int> PartDay(P); //紀錄每個團體的罷工周期
       for(int i = 0 ; i < P ; i++) cin >> PartDay[i];

       vector<bool> WeNeedREST (N+1 , 0); 
       /*記錄從1到第N天的罷工情形，1是有罷工，
       因為陣列的索引是從0開始到N-1，
       總大小是N，為求方便記錄，設定大小為N+1，即0到N，並從WeNeedREST[1]開始記錄*/
        for (int i : PartDay)
        {
            for (int day = i; day <= N; day += i) //遍歷每一個團體的罷工周期，並以其倍數進行迴圈，符合條件者即在bool陣列紀錄為罷工日
            {
                int Todayiswhatday = day % 7 ; // =1是星期日 =0是星期六，題目說星期五星期六罷工不計算
                if(Todayiswhatday == 6 || Todayiswhatday == 0) continue;
                WeNeedREST[day] = 1; //雖然題目說週五週六不能算，但實際上其他日子不用在乎今天星期幾
            }
            
        }
        
        int Howmanyrestdays = 0;
        for (size_t i = 1; i <= N; i++) //遍歷罷工日列表。為1者記錄為罷工日
        {
            if(WeNeedREST[i] == 1) Howmanyrestdays++;
        }
        cout << Howmanyrestdays << "\n";
    }
    return 0;
}