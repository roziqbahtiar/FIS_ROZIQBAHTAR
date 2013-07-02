#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#ifndef MAX
# define MAX(x,y) ( (x) > (y) ? (x) : (y) )
#endif
#ifndef MIN
# define MIN(x,y) ( (x) < (y) ? (x) : (y) )
#endif


float orderSedikit,orderSedang, orderBanyak, stockSedikit, stockSedang, stockBanyak;
float output_jumlahProduksi[2];
float produksi,temp[4] = {0,0,0,0};
char *isProduksi, *permintaan, *persediaan;
float triangle(float x,float a,float b, float c){
    float result[3];
//    if(_stock <= a || _stock >= c){
//        result = 0;
//    }
//    else if (_stock >= a && _stock <= b ){
//        result = (_stock - a)/(b- a);
//    }
//    else if (_stock >= b && _stock <= c ){
//        result = (c - _stock)/(c-b);
//    }
//    return result;
    //DOUBLE a = params[0], b = params[1], c = params[2];

	if (a>b)
		//fisError("Illegal parameters in fisTriangleMf() --> a > b");
	if (b>c)
		//fisError("Illegal parameters in fisTriangleMf() --> b > c");

	if (a == b && b == c)
		return(x == a);
	if (a == b)
		return((c-x)/(c-b)*(b<=x)*(x<=c));
	if (b == c)
		return((x-a)/(b-a)*(a<=x)*(x<=b));
	return(MAX(MIN((x-a)/(b-a), (c-x)/(c-b)), 0));
}
float trapesium(float _stock,float a,float b, float c,float d){
    float result=0;

    if(_stock <=a || _stock>=d){
        return result = 0;
    }
    if(_stock >= a && _stock <=b){
        result = (_stock - a)/(b- a);
        return result;
    }
    if(_stock >= b && _stock <= c){
        return result =1;
    }
    if(_stock >= c && _stock <= d){
        result = (d - _stock)/(d-c);
        return result;
    }
}

void ruleFuzzy(){
    isProduksi = NULL;
    if(permintaan == "sedikit-sedang" && persediaan == "sedikit-sedang"){
        //if order is sediki and stock is sedikit
        temp[0] = MIN(orderSedikit,stockSedikit); //then produksi is sedikit
        //if order is sediki and stock is sedang
        temp[1] = MIN(orderSedikit,stockSedang);
        //if order is sedang and stock is sedikit
        temp[2] = MIN(orderSedang,stockSedikit);//then produksi is sedikit
        //if order sedang and stock is sedang
        temp[3] = MIN(orderSedang,stockSedang);

        //using MAX METHOD
        produksi = MAX(MAX(temp[0],temp[1]),MAX(temp[2],temp[3]));
        if(produksi == temp[0]){isProduksi = "Sedikit"; permintaan = "Sedikit";persediaan = "Sedikit";}
        if(produksi == temp[1]){isProduksi = "Not Define";permintaan = "Sedikit";persediaan = "Sedang";}
        if(produksi == temp[2]){isProduksi = "Sedikit";permintaan = "Sedang";persediaan = "Sedikit";}
        if(produksi == temp[3]){isProduksi = "Not Define";permintaan = "Sedang";persediaan = "Sedang";}
    }
    else if(permintaan=="sedikit-sedang" && persediaan=="sedang-banyak"){
        //if order is sediki and stock is sedikit
        temp[0] = MIN(orderSedikit,stockSedang);
        //if order is Sedang and stock is Sedikit
        temp[1] = MIN(orderSedikit,stockBanyak);
        //if order is sedang and stock is sedang
        temp[2] = MIN(orderSedang,stockSedang);
        //if order is sedang and stock is banyak
        temp[3] = MIN(orderSedang,stockBanyak);
        int i;
        for (i=0;i<4;i++)printf("%f\n",temp[i]);
        //produksi = MAX(MAX(temp[0],temp[1]),temp[2]);
        produksi = MAX(MAX(temp[0],temp[1]),MAX(temp[2],temp[3]));
        if(produksi == temp[0]){isProduksi = "Not Define";permintaan = "Sedikit";persediaan = "Sedang";}
        if(produksi == temp[1]){isProduksi = "Not Define";permintaan = "Sedikit";persediaan = "Banyak";}
        if(produksi == temp[2]){isProduksi = "Not Define";permintaan = "Sedang";persediaan = "Sedang";}
        if(produksi == temp[3]){isProduksi = "Banyak";permintaan = "Sedang";persediaan = "Banyak";}
    }
     else if(permintaan=="sedang-banyak" && persediaan=="sedikit-sedang"){
        //if order is sediki and stock is sedikit
        temp[0] = MIN(orderSedang,stockSedikit);
        //if order is sedang and stock is sedang
        temp[1] = MIN(orderSedang,stockSedang);
        //if order is bnyak and stock is sedikit
        temp[2] = MIN(orderBanyak,stockSedikit);
        //if order is banyak and stock is sedang
        temp[3] = MIN(orderBanyak,stockSedang);
        int i;
        for (i=0;i<4;i++)printf("%f\n",temp[i]);
        //produksi = MAX(MAX(temp[0],temp[1]),temp[2]);
        produksi = MAX(MAX(temp[0],temp[1]),MAX(temp[2],temp[3]));
        if(produksi == temp[0]){isProduksi = "Sedikit";permintaan ="Sedang";persediaan = "Sedikit";}
        if(produksi == temp[1]){isProduksi = "Not Define";permintaan = "Sedang";persediaan = "Sedang";}
        if(produksi == temp[2]){isProduksi = "Sedikit";permintaan = "Banyak";persediaan = "Sedikit";}
        if(produksi == temp[3]){isProduksi = "Banyak";permintaan = "Banyak";persediaan = "Sedang";}
    }
    else if(permintaan=="sedang-banyak" && persediaan=="sedang-banyak"){
        //if order is sediki and stock is sedikit
        temp[0] = MIN(orderSedang,stockSedang);
        //if order is Sedang and stock is Sedikit
        temp[1] = MIN(orderSedang,stockBanyak);
        //if order is sedang and stock is sedang
        temp[2] = MIN(orderBanyak,stockSedang);
        //if order is sedang and stock is banyak
        temp[3] = MIN(orderBanyak,stockBanyak);
        //produksi = MAX(MAX(temp[0],temp[1]),temp[2]);
        produksi = MAX(MAX(temp[0],temp[1]),MAX(temp[2],temp[3]));
        if(produksi == temp[0]){isProduksi = "Not Define";permintaan ="Sedang";persediaan = "Sedang";}
        if(produksi == temp[1]){isProduksi = "Banyak";permintaan ="Sedang";persediaan = "Banyak";}
        if(produksi == temp[2]){isProduksi = "Banyak";permintaan ="Banyak";persediaan = "Sedang";}
        if(produksi == temp[3]){isProduksi = "Banyak";permintaan ="Banyak";persediaan = "Banyak";}
    }
    else if(permintaan == "sedikit" && persediaan == "sedikit"){
            produksi = MIN(orderSedikit,stockSedikit);
            isProduksi = "Sedikit";
            permintaan ="Sedikit";persediaan = "Sedikit";
    }
     else if(permintaan == "sedikit" && persediaan == "banyak"){
            produksi = MIN(orderSedikit,stockBanyak);
            isProduksi = "Banyak";
            permintaan ="Sedikit";persediaan = "Banyak";
    }
    else if (permintaan == "sedang" && persediaan =="sedikit"){
            produksi = MIN(orderSedang,stockSedikit);
            isProduksi = "Sedikit";
            permintaan ="Sedang";persediaan = "Sedikit";
    }
    else if (permintaan == "banyak"&& persediaan == "sedikit"){
            produksi = MIN(orderBanyak,stockSedikit);
            isProduksi= "Sedikit";
            permintaan ="Banyak";persediaan = "Sedikit";
    }
    else if (permintaan == "banyak"&& persediaan == "sedang"){
            produksi = MIN(orderBanyak,stockSedang);
            isProduksi= "Banyak";
            permintaan ="Banyak";persediaan = "Sedang";
    }
    else if (permintaan == "banyak"&& persediaan == "banyak"){
            produksi = MIN(orderBanyak,stockBanyak);
            isProduksi= "Banyak";
            permintaan ="Banyak";persediaan = "Banyak";
    }
    else if (permintaan == "sedikit" && persediaan == "sedikit-sedang"){
        temp[0] = MIN(orderSedikit,stockSedikit);
        temp[1] = MIN(orderSedikit,stockSedang);
        produksi = MAX(temp[0],temp[1]);
        if(produksi == temp[0]) {isProduksi = "Sedikit"; permintaan = "Sedikit";persediaan = "Sedikit";}
        if(produksi == temp[1]) {isProduksi = "Not Define";permintaan = "Sedikit";persediaan = "Sedang";}
    }
    else if (permintaan == "sedikit" && persediaan == "sedang-banyak"){
        temp[0] = MIN(orderSedikit,stockSedang);
        temp[1] = MIN(orderSedikit,stockBanyak);
        produksi = MAX(temp[0],temp[1]);
        if(produksi == temp[0]) {isProduksi = "Not Define";permintaan ="Sedikit";persediaan = "Sedang";}
        if(produksi == temp[1]) {isProduksi = "Not Define";permintaan ="Sedikit";persediaan = "Banyak";}
    }
    else if (permintaan == "sedang" && persediaan == "sedikit-sedang"){
        temp[0] = MIN(orderSedang,stockSedikit);
        temp[1] = MIN(orderSedang,stockSedang);
        produksi = MAX(temp[0],temp[1]);
        if(produksi == temp[0]) {isProduksi = "Sedikit";permintaan ="Sedang";persediaan = "Sedikit";}
        if(produksi == temp[1]) {isProduksi = "Not Define";permintaan ="Sedang";persediaan = "Sedang";}
    }
    else if (permintaan == "sedang" && persediaan == "sedang-banyak"){
        temp[0] = MIN(orderSedang,stockSedang);
        temp[1] = MIN(orderSedang,stockBanyak);
        produksi = MAX(temp[0],temp[1]);
        if(produksi == temp[0]) {isProduksi = "Not Define";permintaan ="Sedang";persediaan = "Sedang";}
        if(produksi == temp[1]) {isProduksi = "Banyak";permintaan ="Sedang";persediaan = "Banyak";}
    }
    else if (permintaan == "banyak" && persediaan == "sedikit-sedang"){
        temp[0] = MIN(orderBanyak,stockSedikit);
        temp[1] = MIN(orderBanyak,stockSedang);
        produksi = MAX(temp[0],temp[1]);
        if(produksi == temp[0]) {isProduksi = "Sedikit";permintaan ="Banyak";persediaan = "Sedikit";}
        if(produksi == temp[1]) {isProduksi = "Banyak";permintaan ="Banyak";persediaan = "Sedang";}
    }
    else if (permintaan == "banyak" && persediaan == "sedang-banyak"){
        temp[0] = MIN(orderBanyak,stockSedang);
        temp[1] = MIN(orderBanyak,stockBanyak);
        produksi = MAX(temp[0],temp[1]);
        if(produksi == temp[0]) {isProduksi = "Banyak";permintaan ="Banyak";persediaan = "Sedang";}
        if(produksi == temp[1]) {isProduksi = "Banyak";permintaan ="Banyak";persediaan = "Banyak";}
    }
     else if (permintaan == "sedang" && persediaan == "banyak"){
        temp[0] = MIN(orderSedang,stockBanyak);
                isProduksi = "Banyak";permintaan ="Sedang";persediaan = "Banyak";

    }

}

float defuzification(float sum_production){
    float jumlahHasil = 0;
    if (isProduksi == "Sedikit"){
        jumlahHasil = 20 - (sum_production*10)-2.1;
    }

    else if (isProduksi == "Banyak"){
        jumlahHasil = (8 * sum_production)+17;
    }
    else{
             jumlahHasil = 25/2;
    isProduksi = "Not-Define";
    }

    return jumlahHasil;
}
void getMember(int order, int stock){
    if (order>=8&&order<=14){
        orderSedikit = triangle(order,8,11,14);
        permintaan = "sedikit";
    }
    if(order>=13&&order<=14){
        orderSedikit = triangle(order,8,11,14);
        orderSedang = triangle(order,13,16,19);
        permintaan = "sedikit-sedang";

    }
    if(order >=15&&order<=17){
        orderSedang = triangle(order,13,16,19);
        permintaan = "sedang";
    }
    if(order >=18&&order<=19){
        orderSedang = triangle(order,13,16,19);
        orderBanyak = triangle(order,18,21,24);
        permintaan ="sedang-banyak";
    }
    if(order>=20&&order<=24){
        orderBanyak = triangle(order,18,21,24);
        permintaan = "banyak";
    }
    if(order<8||order>24){
        permintaan = "error : out of range";
    }
    //persediaan
    if (stock>=30&&stock<=42){
        stockSedikit= triangle(stock,30,36,42);
        persediaan = "sedikit";
    }
    if(stock>=38&&stock<=42){
        stockSedikit= triangle(stock,30,36,42);
        stockSedang = triangle(stock,38,45,50);
        persediaan = "sedikit-sedang";
    }
    if(stock>=43&&stock<=46){
        stockSedang = triangle(stock,38,45,50);
        persediaan = "sedang";
    }
    if(stock>=47&&stock<=50){
        stockSedang = triangle(stock,38,45,50);
        stockBanyak = triangle(stock,47,55,60);
        persediaan = "sedang-banyak";
    }
    if(stock>=51&&stock<=60){
       stockBanyak = triangle(stock,47,55,60);
        persediaan = "banyak";
    }
    if (stock<30 || stock > 60) {
        persediaan = "error : out of range";
    }
}
void display(){
    printf ("| Input      |   Sedikit    |    Sedang   |    Banyak   |\n");
    printf ("---------------------------------------------------------\n");
    printf("| Permintaan  |   %.3f      |    %.3f     |     %.3f  |\n",orderSedikit,orderSedang, orderBanyak);
    printf("| Persediaan  |   %.3f      |    %.3f     |     %.3f  |\n",stockSedikit, stockSedang, stockBanyak);
    printf ("---------------------------------------------------------\n");
}
int main(){
//input value from permintaan anda persediaan
int order,stock;

printf("\tBerapa jumlah permintaan : ");scanf("%d",&order);
printf("\n\tBerpa jumlah persediaan : ");scanf("%d",&stock);

getMember(order,stock);
display();
ruleFuzzy();
printf("permintaan input key %s\n",permintaan);
printf("persediaan input key %s\n",persediaan);
printf("Maka, Jumlah produksi harus : %s , sejumlah : %.2f\n",isProduksi,defuzification(produksi));
printf("Drajat keanggotaan produksi : %.3f\n\n",produksi);
return 0;
}
