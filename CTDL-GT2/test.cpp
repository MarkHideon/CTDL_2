#include <iostream>
#include <algorithm>
using namespace std;
bool dd[1000], tt = 0; //Mảng đánh dấu tối đa  1000 đỉnh
int dem=1,dem2, n;// dem sử dụng để đếm số bước đi của  đường đi hiện tai, dem2 để lưu số bước của đường đi dài nhát trước đó
int a[1000][1000]; //Mảng để lưu mảng đồ thị
int b[1000], c[1000]; //Mảng c để lưu đường đi dài nhất tìm được tạm thời, mảng b sử dụng trong qua trình tìm 1 đường đi
int u,v; //2 đỉnh u và v
  
//Hàm tìm đường đi dài nhất
void duongdidainhat(int i)
{
    dd[i]=1; //Đánh dấu đỉnh i đã đi qua
  
//Nếu đinh i chính bằng v  tức là từ đỉnh u ta đã đi tới v
    if(i==v)
    {
        tt=1;
    //Phần này chính là vét cạn đó, ta tìm tất cả đường đi rồi so sánh lấy được đường đi dài nhất
      //Nếu đường đi hiện tại tìm được lớn hơn đường đi dài nhất ban đầu
        if(dem > dem2)
        {
          //Gắn đường đi dài nhất bằng đường đi tìm được, gắn lại biến đếm
            for(int j=0;j<dem;j++) c[j]=b[j]; dem2 = dem;
        }
    }
//Nếu chưa tới đỉnh v ta tiếp tục duyệt các đỉnh chưa đi qua
    else for(int j=0;j<n;j++) 
    {
        if(a[i][j] != 0 && dd[j]==0)//Kiểm tra xem giữa 2 đỉnh có tồn tại đường đi không, và đỉnh đó đã đi qua trước đó chưa
        {
            b[dem++] = j; //Tăng biến đếm bước đi lên 1, đồng thời gắn đường đi tại đỉnh j
            duongdidainhat(j); //duyệt đỉnh j tiếp tục tìm kiếm đường đi
            dem--; dd[j]=0;//Thoát khỏi hàm quay lui, lúc này hàm quay lui sẽ lùi về 1 bước phía trước, và tìm kiếm 1 đường đi khác có thể sảy ra.....ta trừ đi biến đếm 1 đơn vị và gắn lại đỉnh đó là chưa đi qua
        }
    }
}
  
//Hàm hiển thị đường đi
void induongdi()
{
    for(int i = 0;i<dem2; i++) cout<<c[i]<<" ";
}
int main()
{
  cout<<"nhap so dinh: "; cin>>n;
    cout<<"Nhap ma tran do thi: \n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
             cin>>a[i][j];
    cout<<"Ma tran do thi: \n";
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<n;j++)
     cout<<a[i][j]<<"  "; cout<<endl;
    }
    cout<<"Nhap dinh u "; cin>>u;
    cout<<"Nhap dinh v "; cin>>v;
    b[0]=u;
    duongdidainhat(u);
    if(tt) induongdi(); else cout<<"Kg ton tai duong di tu u toi v";
      
}