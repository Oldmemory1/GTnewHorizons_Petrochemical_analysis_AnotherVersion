#include"OldMemoryCore.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"�˳�����������ĳ���ض�������������������������䣬ֻһֱ�ѽ�ĳһ�ֻ������ͣ����⼸�ֲ��ѽ�����"<<endl;
	oil Oil;
	All Calc;
	int judge;
	while(true){
	cout<<"����1���������������0�˳��������"<<endl;
	scanf("%d",&judge);
	if(judge==0){
		break;
	}else if(judge==1){
		//donothing
	}else{
		printf("�����������������룡\n");
		continue;
	}
	cout<<"��������Һ�������˳��Ϊ����ȼ�ͣ���ȼ�ͣ�ʯ���ͣ�������"<<endl;
	double a,b,c,d;
	try{
	    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);//���������͵��� 		
	    if(a<0||b<0||c<0||d<0){
	    	throw InvalidValueException;
		}
	}catch(int Exception){
		if(Exception==InvalidValueException){
			cout<<"���벻����Ϊ��ֵ"<<endl;
		}
	}

	Oil.Initialization();
	Oil.SetData(a,b,c,d);
	//Oil.OutPutData();
	Calc.Initialization();
	Calc.ReceivedData(Oil);
	int H,L,N,G;
	cout<<"�������ѻ��ķ�ʽ��������ȼ��-��ȼ��-ʯ����-������ ��˳�򣩣�"<<endl;
	cout<<"��1��6���ֱ��Ӧ���⣬���⣬���⣬������������������������-1��Ӧ�ò��ﲻ�ѽ⣬���������ȼ�ͺ���������0����ֱ������"<<endl;
	cout<<"�������ӣ�"<<endl;
	cout<<"0 1 1 0"<<endl;
	cout<<"������Ӵ�����ȼ�ͺ�������ֱ��������ȼ�ͺ�ʯ����ѡ�������ѻ�"<<endl; 
	//scanf("%d %d %d %d",&H,&L,&N,&G);
	try{
		scanf("%d %d %d %d",&H,&L,&N,&G);
		if(H<-1||H>6||L<-1||L>6||N<-1||N>6||G<-1||G>6||L==0||N==0){
			throw InvalidValueException;
		}
	}catch(int Exception){
		if(Exception==InvalidValueException){
			cout<<"������ѻ���ʽ����"<<endl;
			continue;
		}
	} 
	Calc.GetCrackedType(H,L,N,G);
	Calc.Crack();
	cout<<"�ѻ����ܲ���"<<endl;
	Calc.OutputAllData();		
	}
	return 0;
	system("pause");

}
