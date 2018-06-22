
#include<iostream>
using namespace std;
void Tomauthamlam(int n,int m,int danhsachcanh[100][2],int thututomau[100]){// thuật toán tham lam tô màu
    int color[100][2];int i=0,x=0;
    for(i=0;i<=n-1;i++){//khởi tạo mảng màu
        color[i][0]=i+1;
        color[i][1]=0;
    }

    for(x=0;x<=n-1;x++){//lần lượt xét từng đỉnh và tăng dần màu cho đến khi không trùng màu với đỉnh kề
            color[thututomau[x]-1][1]=1;
        X:for(i=0;i<=m-1;i++){
            if(danhsachcanh[i][0]==thututomau[x]){
                if(color[thututomau[x]-1][1]==color[danhsachcanh[i][1]-1][1]){
                    color[thututomau[x]-1][1]++;
                    goto X;// duyệt lại từ đầu đề phòng sau khi tăng giá trị màu bằng giá trị màu lớn hơn bị bỏ qua từ những lúc duyệt trước
                }
            }
            else if(danhsachcanh[i][1]==thututomau[x]){
                if(color[thututomau[x]-1][1]==color[danhsachcanh[i][0]-1][1]){
                    color[thututomau[x]-1][1]++;
                    goto X;
                }
            }
        }
    }
    for(x=0;x<=n-1;x++){
        cout<<thututomau[x]<<" fill color : "<<color[thututomau[x]-1][1]<<endl;
    }

}
int main(){
    int n=0,m=0,k=0,i=0,j=0,x=0,y=0;
    int danhsachcanh[100][2],danhsachbac[100][2];//tối đa 100 đỉnh và 100 cạnh,có thể tăng kích thước mảng
    int thututomau[100],solanxuathien[100];//để làm bài toán với số lượng lớn hơn
    cout<<"NHAP VAO SO DINH N=";cin>>n;//đầu vào
    if(n==1) cout<<"Xong";
    else{
    cout<<"NHAP VAO SO CANH M=";cin>>m;
    for(i=0;i<=m-1;i++){
        for(j=0;j<=1;j++){
            cin>>danhsachcanh[i][j];// đầu vào danh sách cạch tương tự bài toán Prufer code
        }
    }

    for(k=0;k<=n-1;k++){//khởi tạo mảng chứa bậc các đỉnh
        danhsachbac[k][0]=k+1;
        danhsachbac[k][1]=0;
    }
    for(x=0;x<=n-1;x++){//khởi tạo mảng chứa thứ tự các đỉnh để thuât toán tham lam tô màu
        thututomau[x]=0;
    }
    for(y=0;y<=n-1;y++){//lưu số lần xuất hiện các đỉnh đã được xếp thứ tự trong thututomau[]
        solanxuathien[y]=0;
    }
    for(i=0;i<=m-1;i++){//bac cua cac dinh luu tai danh sach bac
            for(j=0;j<=1;j++){
                danhsachbac[danhsachcanh[i][j]-1][1]++;
            }
    }
    int minn=n;
    for(k=0;k<=n-1;k++){//chọn phần tử đầu tiên cho thututomau[] đảm bảo bậc nhỏ hơn k
        if(danhsachbac[k][1]<minn){
        thututomau[0]=danhsachbac[k][0];
        minn=danhsachbac[k][1];
        }
    }

    solanxuathien[thututomau[0]-1]++;//tăng số lần xuất hiện của phần tử đầu
    int point=0,mark=0;//biến point lưu vị trí của đỉnh đang xét trong thututomau[],mark lưu vị trí để thêm hàng xóm của đỉnh đó vào thututomau[]
    do{//tìm các hàng xóm các đỉnh và xếp xào thututomau[]
        for(i=0;i<=m-1;i++){

                if(thututomau[point]==danhsachcanh[i][0]){
                    if(solanxuathien[danhsachcanh[i][1]-1]==0){
                        mark++;
                        solanxuathien[danhsachcanh[i][1]-1]++;
                        thututomau[mark]=danhsachcanh[i][1];
                    }
                }
                else if(thututomau[point]==danhsachcanh[i][1]){
                    if(solanxuathien[danhsachcanh[i][0]-1]==0){
                        mark++;
                        solanxuathien[danhsachcanh[i][0]-1]++;
                        thututomau[mark]=danhsachcanh[i][0];
                    }
                }
        }
        point++;

    }while(mark<n-1);
    cout<<"THU TU TO MAU CHO THUAT TOAN THAM LAM :";
    for(x=0;x<=n-1;x++){
        cout<<thututomau[x]<<" ";
    }
    cout<<endl;
    Tomauthamlam(n,m,danhsachcanh,thututomau);
    }

    return 0;
}
