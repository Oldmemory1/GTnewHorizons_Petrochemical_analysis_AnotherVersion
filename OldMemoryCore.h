#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>  
#include<cmath>
#include<ctime>
#include<windows.h>
#define OK 1
#define Broken 0
#define InvalidValueException -1
#define GreaterThanTheMaximumValue -1
#define SmallerThanTheMinimumValue -1
using namespace std; 
/*��ĿҪ�󣺱�дһ�����򣬼����15000mbĳ��ԭ�ͳ����ѻ����Բ�������ԭ��*/
class oil{
	private:
	int TypeInInt;
	string TypeInString;
	double HeavyOilAmount;
	double LightOilAmount;
	double NaphthaAmount;
	double GasAmount;
	
	public:
	void GetOilTypeAndAmount(int type){//��ȡԭ�������֣�1��BCԭ�ͣ�2��GT���ͣ�3��GTԭ�ͣ�4��GT���ͣ�5��GT������ 
		switch(type){
			case 1:
				TypeInInt=1;
				TypeInString="BCOil";
				HeavyOilAmount=4500;
				LightOilAmount=15000;
				NaphthaAmount=6000;
				GasAmount=18000;
	            break;
		    case 2:
		    	TypeInInt=2;
		    	TypeInString="GTLightOil";
				HeavyOilAmount=1000;
				LightOilAmount=2000;
				NaphthaAmount=3000;
				GasAmount=24000;
		    	break;
		    case 3:
		    	TypeInInt=3;
		    	TypeInString="GTOil";
				HeavyOilAmount=1500;
				LightOilAmount=7500;
				NaphthaAmount=22500;
				GasAmount=9000;		    
				break;
		    case 4:
			    TypeInInt=4;
			    TypeInString="GTHeavyOil";
			    HeavyOilAmount=37500;
				LightOilAmount=6750;
				NaphthaAmount=2250;
				GasAmount=9000;
			    break;
			case 5:
			    TypeInInt=5;
			    TypeInString="GTExtraHeavyOil";
			    HeavyOilAmount=56250;
				LightOilAmount=10125;
				NaphthaAmount=3375;
				GasAmount=13500;
			    break;
			default:
			    break; 	
	   }
    }
    
    void OutPutData(){//��������������� 
    	cout<<"ԭ�����ͺţ�"<<this->TypeInInt<<endl;
    	cout<<"ԭ�����ͣ�"<<this->TypeInString<<endl;
    	printf("������ȼ��������%lf��������ȼ��������%lf������ʯ����������%lf������������������%lf\n",this->HeavyOilAmount,this->LightOilAmount,this->NaphthaAmount,this->GasAmount);
	}
    double GetHeavyOilAmount(){
    	return this->HeavyOilAmount;
	}
	double GetLightOilAmount(){
		return this->LightOilAmount;
	}
	double GetNaphthaAmount(){
		return this->NaphthaAmount;
	}
	double GetGasAmount(){
		return this->GasAmount;
	}
	void Initialization(){
		this->GasAmount=0;
		this->HeavyOilAmount=0;
		this->NaphthaAmount=0;
		this->LightOilAmount=0;
		this->TypeInInt=-1;
		this->TypeInString="";
	}
	void SetData(double a,double b,double c,double d){//�°�������ڼ���ĳ���ض����������ѽ���� 
		this->HeavyOilAmount=a;
		this->LightOilAmount=b;
		this->NaphthaAmount=c;
		this->GasAmount=d;
	}
};
class All{
	private:
	double HeavyOilAmount;
	double LightOilAmount;
	double NaphthaAmount;
	double GasAmount;
	int GetFuel;//Ϊ0ʱ����������ʮ����Ϊ1ʱ���������ͣ�Ϊ2ʱ��������ʮ�� 
	int HeavyOilCrackedType;//��ȼ���ѻ���ʽ
	// 0��ֱ������ 1��������� 2���ж����� 3���ض����� 4��������� 5���ж����� 6���ض����� 
	int LightOilCrackedType;//��ȼ���ѻ���ʽ 
	// 1��������� 2���ж����� 3���ض����� 4��������� 5���ж����� 6���ض����� 	
	int NaphthaCrackedType;//ʯ�����ѻ���ʽ 
	// 1��������� 2���ж����� 3���ض����� 4��������� 5���ж����� 6���ض����� 	
	int GasCrackedType;//�������ѻ���ʽ 
	// 0��ֱ������ 1��������� 2���ж����� 3���ض����� 4��������� 5���ж����� 6���ض����� 	
	
	//����Ƕ����Product�����洢����
	public:
	class Product{
         friend class All;
		 private:
		 double methane;//���� 
		 double ethane;//���� 
		 double propane;//���� 
		 double butane;//���� 
         double octane;
		 double helium;//����
		 double toluene;//�ױ�
		 double benzene;//��
		 double vinyl;//��ϩ
		 double acrylic;//��ϩ
		 double butene;//��ϩ
		 double butadiene;//����ϩ 
		 double phenol;//���� 
		 double TinyCarbonDust;//С��̼��	
		 double Fuel;//���� 
		 double CetaneBoostedDiesel;//��ʮ�� 
		 public:
		 void Initialization(){
		 	this->methane=0;
		 	this->ethane=0;
		 	this->propane=0;
		 	this->butane=0;
			this->helium=0;
			this->toluene=0;
			this->benzene=0;
			this->vinyl=0;
			this->acrylic=0;
			this->butene=0;
			this->butadiene=0;
			this->TinyCarbonDust=0; 
			this->phenol=0;
            this->octane=0;
            this->Fuel=0;
            this->CetaneBoostedDiesel=0;
		 }
		 void OutPutInformation(){//����ڲ����� 
		 	//cout<<"���������"<<this->methane<<endl;
		 	printf("���������%lf\n",this->methane/(double)15); 
		 	//cout<<"���������"<<this->ethane<<endl;
		 	printf("���������%lf\n",this->ethane/(double)15); 
			//cout<<"���������"<<this->propane<<endl;
		 	printf("���������%lf\n",this->propane/(double)15); 
			//cout<<"���������"<<this->butane<<endl; 
		 	printf("���������%lf\n",this->butane/(double)15); 
			//cout<<"����������"<<this->helium<<endl;
            printf("���������%lf\n",this->octane/(double)15);
		 	printf("����������%lf\n",this->helium/(double)15); 
			//cout<<"�ױ�������"<<this->toluene<<endl;
		 	printf("�ױ�������%lf\n",this->toluene/(double)15); 
			//cout<<"��������"<<this->benzene<<endl;
		 	printf("��������%lf\n",this->benzene/(double)15); 
			//cout<<"��ϩ������"<<this->vinyl<<endl;
		 	printf("��ϩ������%lf\n",this->vinyl/(double)15); 
			//cout<<"��ϩ������"<<this->acrylic<<endl;
		 	printf("��ϩ������%lf\n",this->acrylic/(double)15); 
			//cout<<"��ϩ������"<<this->butene<<endl;
		 	printf("��ϩ������%lf\n",this->butene/(double)15); 
			//cout<<"����ϩ������"<<this->butadiene<<endl;
		 	printf("����ϩ������%lf\n",this->butadiene/(double)15); 
			//cout<<"С��̼�۲�����"<<this->TinyCarbonDust<<endl;
			printf("���Ӳ�����%lf\n",this->phenol/(double)15);
		 	printf("С��̼�۲�����%lf\n",TinyCarbonDust/(double)15);  
		 	printf("���Ͳ�����%lf\n",this->Fuel/(double)15); 
		 	printf("��ʮ��������%lf\n",this->CetaneBoostedDiesel/(double)15);
		 } 
		 void OutPutAllInformation(){
		 	//cout<<"���������"<<this->methane<<endl;
		 	printf("���������%lf\n",this->methane); 
		 	//cout<<"���������"<<this->ethane<<endl;
		 	printf("���������%lf\n",this->ethane); 
			//cout<<"���������"<<this->propane<<endl;
		 	printf("���������%lf\n",this->propane); 
			//cout<<"���������"<<this->butane<<endl; 
		 	printf("���������%lf\n",this->butane); 
			//cout<<"����������"<<this->helium<<endl;
            printf("���������%lf\n",this->octane);
		 	printf("����������%lf\n",this->helium); 
			//cout<<"�ױ�������"<<this->toluene<<endl;
		 	printf("�ױ�������%lf\n",this->toluene); 
			//cout<<"��������"<<this->benzene<<endl;
		 	printf("��������%lf\n",this->benzene); 
			//cout<<"��ϩ������"<<this->vinyl<<endl;
		 	printf("��ϩ������%lf\n",this->vinyl); 
			//cout<<"��ϩ������"<<this->acrylic<<endl;
		 	printf("��ϩ������%lf\n",this->acrylic); 
			//cout<<"��ϩ������"<<this->butene<<endl;
		 	printf("��ϩ������%lf\n",this->butene); 
			//cout<<"����ϩ������"<<this->butadiene<<endl;
		 	printf("����ϩ������%lf\n",this->butadiene); 
			//cout<<"С��̼�۲�����"<<this->TinyCarbonDust<<endl;
			printf("���Ӳ�����%lf\n",this->phenol);
		 	printf("С��̼�۲�����%lf\n",TinyCarbonDust);  
		 	printf("���Ͳ�����%lf\n",this->Fuel); 
		 	printf("��ʮ��������%lf\n",this->CetaneBoostedDiesel);		 	
		 }
		 void MethaneAdd(double num){
		 	this->methane=this->methane+num;
		 }
		 void EthaneAdd(double num){
		 	this->ethane=this->ethane+num;
		 }	
		 void PropaneAdd(double num){
		 	this->propane=this->propane+num;
		 }
		 void ButaneAdd(double num){
		 	this->butane=this->butane+num;
		 }
		 void HeliumAdd(double num){
		 	this->helium=this->helium+num;
		 }
		 void TolueneAdd(double num){
		 	this->toluene=this->toluene+num;
		 }
		 void BenezeAdd(double num){
		 	this->benzene=this->benzene+num;
		 }
		 void VinylAdd(double num){
		 	this->vinyl=this->vinyl+num;
		 }
		 void AcrylicAdd(double num){
		 	this->acrylic=this->acrylic+num; 
		 }
		 void ButeneAdd(double num){
		 	this->butene=this->butene+num;
		 }
		 void ButadieneAdd(double num){
		 	this->butadiene=this->butadiene+num;
		 }
		 void TinyCarbonDustAdd(double num){
		 	this->TinyCarbonDust=this->TinyCarbonDust+num;
		 }
	     void PhenolAdd(double num){
	     	this->phenol=this->phenol+num;
		 }
         void OctaneAdd(double num){
            this->octane=this->octane+num;
         }
         void FuelAdd(double num){
         	this->Fuel=this->Fuel+num;
		 }	
		 void CetaneBoostedDieselAdd(double num){
		 	this->CetaneBoostedDiesel=this->CetaneBoostedDiesel+num;
		 } 
	};
	
	public:
	Product Products;
	void HeavyOilCrack(){//�ѻ���������ȼ�� 
		 switch(this->HeavyOilCrackedType){
		 	case 0://ֱ��������ȼ�� 
		 		Products.BenezeAdd(0.4*this->HeavyOilAmount);
		 		Products.TolueneAdd(0.4*this->HeavyOilAmount);
		 		Products.PhenolAdd(0.25*this->HeavyOilAmount);
                this->HeavyOilAmount=0;
		 		break;
		 	case 1://��������ѻ���ȼ�� 
                Products.MethaneAdd(0.075*this->HeavyOilAmount);
                Products.EthaneAdd(0.075*this->HeavyOilAmount);
                Products.PropaneAdd(0.1*this->HeavyOilAmount);
                Products.ButaneAdd(0.1*this->HeavyOilAmount);
                this->LightOilAmount=this->LightOilAmount+this->HeavyOilAmount*0.6;
                this->NaphthaAmount=this->NaphthaAmount+0.1*this->HeavyOilAmount;
                this->HeavyOilAmount=0;
		 		break;
		 	case 2://�ж������ѻ���ȼ��
                Products.MethaneAdd(0.1*this->HeavyOilAmount);
                Products.EthaneAdd(0.1*this->HeavyOilAmount);
                Products.PropaneAdd(0.15*this->HeavyOilAmount);
                Products.ButaneAdd(0.15*this->HeavyOilAmount);
                this->LightOilAmount=this->LightOilAmount+this->HeavyOilAmount*0.4;
                this->NaphthaAmount=this->NaphthaAmount+0.4*this->HeavyOilAmount;
                this->HeavyOilAmount=0;               
		 		break;
		 	case 3://�ض������ѻ���ȼ��
                Products.MethaneAdd(0.175*this->HeavyOilAmount);
                Products.EthaneAdd(0.175*this->HeavyOilAmount);
                Products.PropaneAdd(0.3*this->HeavyOilAmount);
                Products.ButaneAdd(0.3*this->HeavyOilAmount);
                this->LightOilAmount=this->LightOilAmount+this->HeavyOilAmount*0.2;
                this->NaphthaAmount=this->NaphthaAmount+0.25*this->HeavyOilAmount;
                this->HeavyOilAmount=0;        
		 		break;
		 	case 4://��������ѻ���ȼ��
                Products.TolueneAdd(0.025*this->HeavyOilAmount);
                Products.BenezeAdd(0.125*this->HeavyOilAmount);
                Products.ButeneAdd(0.025*this->HeavyOilAmount);
                Products.ButadieneAdd(0.015*this->HeavyOilAmount);
                Products.PropaneAdd(0.003*this->HeavyOilAmount);
                Products.AcrylicAdd(0.03*this->HeavyOilAmount);
                Products.EthaneAdd(0.005*this->HeavyOilAmount);
                Products.VinylAdd(0.05*this->HeavyOilAmount);
                Products.MethaneAdd(0.05*this->HeavyOilAmount);
                Products.TinyCarbonDustAdd(0.001*this->HeavyOilAmount);
                this->LightOilAmount=this->LightOilAmount+this->HeavyOilAmount*0.3;
                this->NaphthaAmount=this->NaphthaAmount+0.05*this->HeavyOilAmount;
                this->HeavyOilAmount=0;
		 		break;
		 	case 5://�ж������ѻ���ȼ��
                Products.TolueneAdd(0.04*this->HeavyOilAmount);
                Products.BenezeAdd(0.2*this->HeavyOilAmount);
                Products.ButeneAdd(0.04*this->HeavyOilAmount);
                Products.ButadieneAdd(0.025*this->HeavyOilAmount);
                Products.PropaneAdd(0.005*this->HeavyOilAmount);
                Products.AcrylicAdd(0.05*this->HeavyOilAmount);
                Products.EthaneAdd(0.007*this->HeavyOilAmount);
                Products.VinylAdd(0.075*this->HeavyOilAmount);
                Products.MethaneAdd(0.075*this->HeavyOilAmount);
                Products.TinyCarbonDustAdd(0.002*this->HeavyOilAmount);
                this->LightOilAmount=this->LightOilAmount+this->HeavyOilAmount*0.2;
                this->NaphthaAmount=this->NaphthaAmount+0.2*this->HeavyOilAmount;
                this->HeavyOilAmount=0;
		 		break;
		 	case 6://�ض������ѻ���ȼ��
                Products.TolueneAdd(0.08*this->HeavyOilAmount);
                Products.BenezeAdd(0.4*this->HeavyOilAmount);
                Products.ButeneAdd(0.08*this->HeavyOilAmount);
                Products.ButadieneAdd(0.05*this->HeavyOilAmount);
                Products.PropaneAdd(0.01*this->HeavyOilAmount);
                Products.AcrylicAdd(0.1*this->HeavyOilAmount);
                Products.EthaneAdd(0.015*this->HeavyOilAmount);
                Products.VinylAdd(0.15*this->HeavyOilAmount);
                Products.MethaneAdd(0.15*this->HeavyOilAmount);
                Products.TinyCarbonDustAdd(0.003*this->HeavyOilAmount);
                this->LightOilAmount=this->LightOilAmount+this->HeavyOilAmount*0.1;
                this->NaphthaAmount=this->NaphthaAmount+0.125*this->HeavyOilAmount;
                this->HeavyOilAmount=0;
		 		break;
		 	case -1://���ѻ� 
			    break; 
		 } 
	}
	void LightOilCrack(){//�ѻ���������ȼ�� 
		switch(this->LightOilCrackedType){
            case 1://��������ѻ���ȼ��
                Products.OctaneAdd(0.1*this->LightOilAmount);
                Products.ButaneAdd(0.15*this->LightOilAmount);
                Products.PropaneAdd(0.2*this->LightOilAmount);
                Products.EthaneAdd(0.125*this->LightOilAmount);
                Products.MethaneAdd(0.125*this->LightOilAmount);
                this->NaphthaAmount=this->NaphthaAmount+0.8*this->LightOilAmount;
                this->LightOilAmount=0;
                break;
            case 2://�ж������ѻ���ȼ��
                Products.OctaneAdd(0.05*this->LightOilAmount);
                Products.ButaneAdd(0.2*this->LightOilAmount);
                Products.PropaneAdd(1.1*this->LightOilAmount);
                Products.EthaneAdd(0.4*this->LightOilAmount);
                Products.MethaneAdd(0.4*this->LightOilAmount);
                this->NaphthaAmount=this->NaphthaAmount+0.5*this->LightOilAmount;
                this->LightOilAmount=0;
                break;                
            case 3://�ض������ѻ���ȼ��
                Products.OctaneAdd(0.02*this->LightOilAmount);
                Products.ButaneAdd(0.125*this->LightOilAmount);
                Products.PropaneAdd(0.125*this->LightOilAmount);
                Products.EthaneAdd(1.5*this->LightOilAmount);
                Products.MethaneAdd(1.5*this->LightOilAmount);
                this->NaphthaAmount=this->NaphthaAmount+0.2*this->LightOilAmount;
                this->LightOilAmount=0;
                break;
            case 4://��������ѻ���ȼ��
                Products.TolueneAdd(0.04*this->LightOilAmount);
                Products.BenezeAdd(0.2*this->LightOilAmount);
                Products.ButeneAdd(0.075*this->LightOilAmount);
                Products.ButadieneAdd(0.06*this->LightOilAmount);
                Products.PropaneAdd(0.02*this->LightOilAmount);
                Products.AcrylicAdd(0.15*this->LightOilAmount);
                Products.EthaneAdd(0.01*this->LightOilAmount);
                Products.VinylAdd(0.05*this->LightOilAmount);
                Products.MethaneAdd(0.05*this->LightOilAmount);
                Products.TinyCarbonDustAdd(0.001*this->LightOilAmount);
                this->HeavyOilAmount=this->HeavyOilAmount+0.15*this->LightOilAmount;
                this->NaphthaAmount=this->NaphthaAmount+0.4*this->LightOilAmount;
                this->LightOilAmount=0;
		 		break;                
            case 5://�ж������ѻ���ȼ��
                Products.TolueneAdd(0.05*this->LightOilAmount);
                Products.BenezeAdd(0.3*this->LightOilAmount);
                Products.ButeneAdd(0.09*this->LightOilAmount);
                Products.ButadieneAdd(0.075*this->LightOilAmount);
                Products.PropaneAdd(0.035*this->LightOilAmount);
                Products.AcrylicAdd(0.2*this->LightOilAmount);
                Products.EthaneAdd(0.03*this->LightOilAmount);
                Products.VinylAdd(0.15*this->LightOilAmount);
                Products.MethaneAdd(0.15*this->LightOilAmount);
                Products.TinyCarbonDustAdd(0.002*this->LightOilAmount);
                this->HeavyOilAmount=this->HeavyOilAmount+0.1*this->LightOilAmount;
                this->NaphthaAmount=this->NaphthaAmount+0.25*this->LightOilAmount;
                this->LightOilAmount=0;
		 		break;              
            case 6://�ض������ѻ���ȼ��
                Products.TolueneAdd(0.03*this->LightOilAmount);
                Products.BenezeAdd(0.15*this->LightOilAmount);
                Products.ButeneAdd(0.065*this->LightOilAmount);
                Products.ButadieneAdd(0.05*this->LightOilAmount);
                Products.PropaneAdd(0.05*this->LightOilAmount);
                Products.AcrylicAdd(0.25*this->LightOilAmount);
                Products.EthaneAdd(0.05*this->LightOilAmount);
                Products.VinylAdd(0.25*this->LightOilAmount);
                Products.MethaneAdd(0.25*this->LightOilAmount);
                Products.TinyCarbonDustAdd(0.003*this->LightOilAmount);
                this->HeavyOilAmount=this->HeavyOilAmount+0.05*this->LightOilAmount;
                this->NaphthaAmount=this->NaphthaAmount+0.1*this->LightOilAmount;
                this->LightOilAmount=0;
		 		break; 
		 	case -1:
		 		break;
        }
	}
	void NaphthaCrack(){//�ѻ�������ʯ���� 
		switch(this->NaphthaCrackedType){
            case 1://��������ѻ�ʯ����
                Products.ButaneAdd(0.8*this->NaphthaAmount);
                Products.PropaneAdd(0.3*this->NaphthaAmount);
                Products.EthaneAdd(0.25*this->NaphthaAmount);
                Products.MethaneAdd(0.25*this->NaphthaAmount);
                this->NaphthaAmount=0;
                break;
            case 2://�ж������ѻ�ʯ����
                Products.ButaneAdd(0.2*this->NaphthaAmount);
                Products.PropaneAdd(1.1*this->NaphthaAmount);
                Products.EthaneAdd(0.4*this->NaphthaAmount);
                Products.MethaneAdd(0.4*this->NaphthaAmount);
                this->NaphthaAmount=0;
                break;
            case 3://�ض������ѻ�ʯ����
                Products.ButaneAdd(0.125*this->NaphthaAmount);
                Products.PropaneAdd(0.125*this->NaphthaAmount);
                Products.EthaneAdd(1.5*this->NaphthaAmount);
                Products.MethaneAdd(1.5*this->NaphthaAmount);
                this->NaphthaAmount=0;
                break;
            case 4://��������ѻ�ʯ����
                Products.TolueneAdd(0.04*this->NaphthaAmount);
                Products.BenezeAdd(0.15*this->NaphthaAmount);
                Products.ButeneAdd(0.08*this->NaphthaAmount);
                Products.ButadieneAdd(0.15*this->NaphthaAmount);
                Products.PropaneAdd(0.015*this->NaphthaAmount);
                Products.AcrylicAdd(0.2*this->NaphthaAmount);
                Products.EthaneAdd(0.035*this->NaphthaAmount);
                Products.VinylAdd(0.2*this->NaphthaAmount);
                Products.MethaneAdd(0.2*this->NaphthaAmount);
                Products.TinyCarbonDustAdd(0.001*this->NaphthaAmount);
                this->LightOilAmount=this->LightOilAmount+this->NaphthaAmount*0.15;
                this->HeavyOilAmount=this->HeavyOilAmount+0.075*this->NaphthaAmount;
                this->NaphthaAmount=0;
		 		break;  
            case 5://�ж������ѻ�ʯ����
                Products.TolueneAdd(0.03*this->NaphthaAmount);
                Products.BenezeAdd(0.125*this->NaphthaAmount);
                Products.ButeneAdd(0.065*this->NaphthaAmount);
                Products.ButadieneAdd(0.1*this->NaphthaAmount);
                Products.PropaneAdd(0.03*this->NaphthaAmount);
                Products.AcrylicAdd(0.4*this->NaphthaAmount);
                Products.EthaneAdd(0.05*this->NaphthaAmount);
                Products.VinylAdd(0.35*this->NaphthaAmount);
                Products.MethaneAdd(0.35*this->NaphthaAmount);
                Products.TinyCarbonDustAdd(0.002*this->NaphthaAmount);
                this->LightOilAmount=this->LightOilAmount+this->NaphthaAmount*0.1;
                this->HeavyOilAmount=this->HeavyOilAmount+0.05*this->NaphthaAmount;
                this->NaphthaAmount=0;
		 		break;
            case 6://�ض������ѻ�ʯ����
                Products.TolueneAdd(0.02*this->NaphthaAmount);
                Products.BenezeAdd(0.1*this->NaphthaAmount);
                Products.ButeneAdd(0.05*this->NaphthaAmount);
                Products.ButadieneAdd(0.05*this->NaphthaAmount);
                Products.PropaneAdd(0.015*this->NaphthaAmount);
                Products.AcrylicAdd(0.3*this->NaphthaAmount);
                Products.EthaneAdd(0.065*this->NaphthaAmount);
                Products.VinylAdd(0.5*this->NaphthaAmount);
                Products.MethaneAdd(0.5*this->NaphthaAmount);
                Products.TinyCarbonDustAdd(0.003*this->NaphthaAmount);
                this->LightOilAmount=this->LightOilAmount+this->NaphthaAmount*0.05;
                this->HeavyOilAmount=this->HeavyOilAmount+0.025*this->NaphthaAmount;
                this->NaphthaAmount=0;
		 		break;
		 	case -1:
		 		break;
        }
	}
    void GasCrack(){//�ѻ�������������
        switch(this->GasCrackedType){
            case 0:
                Products.ButaneAdd(0.06*this->GasAmount);
                Products.PropaneAdd(0.07*this->GasAmount);
                Products.EthaneAdd(0.1*this->GasAmount);
                Products.MethaneAdd(0.75*this->GasAmount);
                Products.HeliumAdd(0.02*this->GasAmount);
                this->GasAmount=0; 
                break;
            case 1:
                Products.HeliumAdd(0.1*this->GasAmount);
                Products.MethaneAdd(1.3*this->GasAmount);
                this->GasAmount=0; 
                break;
            case 2:
                Products.HeliumAdd(0.15*this->GasAmount);
                Products.MethaneAdd(1.4*this->GasAmount);
                this->GasAmount=0; 
                break;
            case 3:               
                Products.HeliumAdd(0.2*this->GasAmount);
                Products.MethaneAdd(1.5*this->GasAmount);
                this->GasAmount=0; 
                break;
            case 4:
                Products.HeliumAdd(0.05*this->GasAmount);
                Products.MethaneAdd(0.5*this->GasAmount);
                Products.VinylAdd(0.1*this->GasAmount);
                Products.EthaneAdd(0.01*this->GasAmount);
                Products.AcrylicAdd(0.05*this->GasAmount);
                Products.TinyCarbonDustAdd(0.001*this->GasAmount);
                this->GasAmount=0;
                break;
            case 5:
                Products.HeliumAdd(0.07*this->GasAmount);
                Products.MethaneAdd(0.6*this->GasAmount);
                Products.VinylAdd(0.2*this->GasAmount);
                Products.EthaneAdd(0.05*this->GasAmount);
                Products.AcrylicAdd(0.01*this->GasAmount);
                Products.TinyCarbonDustAdd(0.001*this->GasAmount);
                this->GasAmount=0;
                break;
            case 6:
                Products.HeliumAdd(0.01*this->GasAmount);
                Products.MethaneAdd(0.7*this->GasAmount);
                Products.VinylAdd(0.3*this->GasAmount);
                Products.EthaneAdd(0.01*this->GasAmount);
                Products.AcrylicAdd(0.01*this->GasAmount);
                Products.TinyCarbonDustAdd(0.001*this->GasAmount);
                this->GasAmount=0;
                break;
            case -1:
			    break; 
        } 
    }
	void Initialization(){//��ʼ������ 
		HeavyOilAmount=0;
		LightOilAmount=0;
		NaphthaAmount=0;
		GasAmount=0;
		HeavyOilCrackedType=-1;
		LightOilCrackedType=-1;
		NaphthaCrackedType=-1;
		GasCrackedType=-1;
		this->Products.Initialization();
		GetFuel=0; 
	}
	void GetCrackedType(int H,int L,int N,int G){//��ȡ�ѻ��ķ�ʽ 
		HeavyOilCrackedType=H;
		LightOilCrackedType=L;
		NaphthaCrackedType=N; 
		GasCrackedType=G;
	}
	void ReceivedData(oil Oil){//��oil���л�ȡ�͵���Ŀ 
		this->NaphthaAmount=Oil.GetNaphthaAmount();
		this->HeavyOilAmount=Oil.GetHeavyOilAmount();
		this->GasAmount=Oil.GetGasAmount();
		this->LightOilAmount=Oil.GetLightOilAmount(); 
	}
	void OutputData(){//����ڲ�������Ϣ 
		printf("��ȼ������%lf����ȼ������%lf��ʯ��������%lf������������%lf\n",this->HeavyOilAmount,this->LightOilAmount,this->NaphthaAmount,this->GasAmount);
		this->Products.OutPutInformation();
	}
	void OutputAllData(){
		printf("��ȼ������%lf����ȼ������%lf��ʯ��������%lf������������%lf\n",this->HeavyOilAmount,this->LightOilAmount,this->NaphthaAmount,this->GasAmount);
		this->Products.OutPutAllInformation();		
	}
	void Crack(){
		while((this->HeavyOilAmount>1e-7&&this->HeavyOilCrackedType!=-1)||(this->LightOilAmount>1e-7&&this->LightOilCrackedType!=-1)||(this->NaphthaAmount>1e-7&&this->NaphthaCrackedType!=-1)||(this->GasAmount>1e-7&&this->GasCrackedType!=-1)){
			this->HeavyOilCrack();
			this->LightOilCrack();
			this->NaphthaCrack();
			this->GasCrack();
			//printf("%lf %lf %lf %lf\n",this->HeavyOilAmount,this->LightOilAmount,this->NaphthaAmount,this->GasAmount);
		}
	}
	void MakeFuel(){
		if(this->GetFuel==1||this->GetFuel==2){
			if(this->LightOilAmount>=5*this->HeavyOilAmount){
				this->LightOilAmount=this->LightOilAmount-5*this->HeavyOilAmount;
				Products.FuelAdd(this->HeavyOilAmount*6);
				this->HeavyOilAmount=0;
			}else if(this->LightOilAmount<5*this->HeavyOilAmount){
				this->HeavyOilAmount=this->HeavyOilAmount-this->LightOilAmount/5;
				Products.FuelAdd(this->LightOilAmount*1.2);
				this->LightOilAmount=0;
			}
		}else if(this->GetFuel==0){
			//donothing;
		}
	}
	void IfGetFuel(int c){
		this->GetFuel=c;
	}	
	void MakeCetaneBoostedDiesel(){
		if(this->GetFuel==2){
			//���ж���ϩ�������ã���������ã����ϳɸ�ʮ��
			if(Products.vinyl>=0.01*Products.Fuel){//��ϩ����
                Products.vinyl=Products.vinyl-Products.Fuel/(double)100;
                Products.CetaneBoostedDiesel=Products.Fuel;
                Products.Fuel=0;
            }else if(Products.vinyl<0.01*Products.Fuel){
                Products.CetaneBoostedDiesel=Products.vinyl*100;
                Products.Fuel=Products.Fuel-100*Products.vinyl;
                Products.vinyl=0;
            }
		}else{
			//donothing
		}
	}
}; 

