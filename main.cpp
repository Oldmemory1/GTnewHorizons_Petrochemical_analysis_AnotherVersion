#include"OldMemoryCore.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"此程序用来计算某种特定情况，对于任意的四种流体搭配，只一直裂解某一种或两种油，另外几种不裂解的情况"<<endl;
	oil Oil;
	All Calc;
	int judge;
	while(true){
	cout<<"输入1启动运算程序，输入0退出运算程序"<<endl;
	scanf("%d",&judge);
	if(judge==0){
		break;
	}else if(judge==1){
		//donothing
	}else{
		printf("输入有误，请重新输入！\n");
		continue;
	}
	cout<<"输入四种液体的量，顺序为：重燃油，轻燃油，石脑油，炼油气"<<endl;
	double a,b,c,d;
	try{
	    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);//读入四种油的量 		
	    if(a<0||b<0||c<0||d<0){
	    	throw InvalidValueException;
		}
	}catch(int Exception){
		if(Exception==InvalidValueException){
			cout<<"输入不可以为负值"<<endl;
		}
	}

	Oil.Initialization();
	Oil.SetData(a,b,c,d);
	//Oil.OutPutData();
	Calc.Initialization();
	Calc.ReceivedData(Oil);
	int H,L,N,G;
	cout<<"请输入裂化的方式（按照重燃油-轻燃油-石脑油-炼油气 的顺序）："<<endl;
	cout<<"从1到6，分别对应轻氢，中氢，重氢，轻蒸汽，中蒸汽，重蒸汽，-1对应该产物不裂解，此外对于重燃油和炼油气，0代表直接蒸馏"<<endl;
	cout<<"输入例子："<<endl;
	cout<<"0 1 1 0"<<endl;
	cout<<"这个例子代表，重燃油和炼油气直接蒸馏，轻燃油和石脑油选择轻氢裂化"<<endl; 
	//scanf("%d %d %d %d",&H,&L,&N,&G);
	try{
		scanf("%d %d %d %d",&H,&L,&N,&G);
		if(H<-1||H>6||L<-1||L>6||N<-1||N>6||G<-1||G>6||L==0||N==0){
			throw InvalidValueException;
		}
	}catch(int Exception){
		if(Exception==InvalidValueException){
			cout<<"输入的裂化方式有误！"<<endl;
			continue;
		}
	} 
	Calc.GetCrackedType(H,L,N,G);
	Calc.Crack();
	cout<<"裂化后总产物"<<endl;
	Calc.OutputAllData();		
	}
	return 0;
	system("pause");

}
