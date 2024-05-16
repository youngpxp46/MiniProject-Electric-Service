#include <stdio.h>
#include <conio.h>
#include <math.h>

struct sevicetotal
{
    float service;
    float total_ele;
    float vat;
    float total;
    float eleft;
}pw;
float ft = 0.9343;
float basereactive = 56.07;

int show(char x[50],int y,int c)
{
    int k;
    if (y == c)
    {
        printf("\n%s\n",x);
        for (k = 40; k > 0; k--)
        {
            printf("*");
        }
        printf("\n");
    }
    else
    {
        printf("*");
        show(x,y-1,c);
    }
}

int calreactivepower(float powre,float rp)
{
    float totalres ;
    
    totalres=sqrt(pow(powre,2)+pow(rp,2));
	totalres=powre/totalres;
	if (totalres < 0.85)
	{
		totalres = (rp-(powre*61.97/100))*56.07;
	}
	else
	{
		totalres = 0;
	}
    return(totalres);
}

int calculator(float ele,int x, float y)
{
    pw.eleft = ele;
    if (x == 0)
    {
        pw.total = ele * y;
    }
    
    else if (x == 1)
    {
        if (ele >= 0 && ele <= 15)
        {
            pw.total = ele * 2.3488;
        }
        else if (ele >= 16 && ele <= 25)
        {
            pw.total = 15 * 2.3488;
            ele = ele - 15;
            ele = ele * 2.9882;
            pw.total = pw.total + ele;
        }
        else if (ele >= 26 && ele <= 35)
        {
            pw.total = 15 * 2.3488;
            ele = ele - 15;
            pw.total = pw.total+(10 * 2.9882);
            ele = ele - 10;
            ele = ele * 3.2405;
            pw.total = pw.total + ele; 
        }
        else if (ele >= 36 && ele <= 100) 
        {
            pw.total = 15 * 2.3488;
            ele = ele - 15;
            pw.total = pw.total+(10 * 2.9882); 
            ele = ele - 10; 
            pw.total = pw.total+(10 * 3.2405);
            ele = ele - 10;
            ele = ele * 3.6237;
            pw.total = pw.total + ele;
        }

        else if (ele >= 101 && ele <= 150) 
        {                           
            pw.total = 15 * 2.3488;
            ele = ele - 15;
            pw.total = pw.total+(10 * 2.9882); 
            ele = ele - 10; 
            pw.total = pw.total+(10 * 3.2405); 
            ele = ele - 10;      
            pw.total = pw.total+(65 * 3.6237); 
            ele = ele - 65;      
            ele = ele * 3.7171;      
            pw.total = pw.total + ele; 
        }
        else if (ele >= 151 && ele <= 400)
        {
            pw.total = 15 * 2.3488;
            ele = ele - 15;
            pw.total = pw.total+(10 * 2.9882); 
            ele = ele - 10; 
            pw.total = pw.total+(10 * 3.2405); 
            ele = ele - 10;      
            pw.total = pw.total+(65 * 3.6237); 
            ele = ele - 65;
            pw.total = pw.total+(50 * 3.7171);
            ele = ele - 50;
            ele = ele * 4.2218;
            pw.total = pw.total + ele;
        }
        else
        {
            pw.total = 15 * 2.3488;
            ele = ele - 15;
            pw.total = pw.total+(10 * 2.9882); 
            ele = ele - 10; 
            pw.total = pw.total+(10 * 3.2405); 
            ele = ele - 10;      
            pw.total = pw.total+(65 * 3.6237); 
            ele = ele - 65;
            pw.total = pw.total+(50 * 3.7171);
            ele = ele - 50;
            pw.total = pw.total+(250 * 4.2218);
            ele = ele - 250;
            ele = ele * 4.4217;
            pw.total = pw.total + ele;
        }
    }
    else if (x == 2)
    {
        if (ele >= 0 && ele <= 150)
        {
            pw.total = ele * 3.2484;
        }
        else if (ele >= 151 && ele <= 400)
        {
            pw.total = 150 * 3.2484;
            ele = ele - 150;
            ele = ele * 4.2218;
            pw.total = pw.total + ele;
        }
        else
        {
            pw.total = 150 * 3.2484;
            ele = ele - 150;
            pw.total = pw.total+(250 * 4.2218);
            ele = ele - 250;
            ele = ele * 4.4217;
            pw.total = pw.total + ele; 
        }
    }
    
    pw.total_ele = pw.total+pw.service;
    printf("\nElectic energe = %.2f",pw.total);
    printf("\nService = %.2f",pw.service);
    printf("\nTotal electic = %.2f",pw.total_ele);
    ft =  pw.eleft*ft;
    printf("\nElectic energe * Ft = %.2f",ft);
    pw.vat = (pw.total_ele+ft)*7/100;
    printf("\nVAT = %.2f",pw.vat);
    pw.total_ele = pw.total_ele+ft+pw.vat;
    printf("\nTotal electic = %.2f",pw.total_ele);
    getch();
}

int calculatorTOU(float ele1,float peak,float ele2,float offpeak)
{
    pw.total_ele = (ele1*peak)+(ele2*offpeak)+pw.service;
    printf("\nElectic energe = %.2f",(ele1*peak)+(ele2*offpeak));
    printf("\nService = %.2f",pw.service);
    printf("\nTotal electic = %.2f",pw.total_ele);
    ft = (ele1+ele2)*ft;
    printf("\nElectic energe * Ft = %.2f",ft);
    pw.vat = (pw.total_ele+ft)*7/100;
    printf("\nVAT = %.2f",pw.vat);
    pw.total_ele = pw.total_ele+ft+pw.vat;
    printf("\nTotal electic = %.2f",pw.total_ele);
    getch();
}

int calculatorpowreq(float ele,float energe,float powre,float powreq,float rp)
{
    rp = calreactivepower(powre,rp);
    pw.total_ele = (ele*energe)+(powre*powreq)+pw.service;
    printf("\nElectic energe = %.2f",ele*energe);
    printf("\nService = %.2f",pw.service);
    printf("\nReactive power = %.2f",rp);
    printf("\nTotal electic = %.2f",pw.total_ele);
    ft = ele*ft;
    printf("\nElectic energe * Ft = %.2f",ft);
    pw.vat = (pw.total_ele+ft+rp)*7/100;
    printf("\nVAT = %.2f",pw.vat);
    pw.total_ele = pw.total_ele+ft+rp+pw.vat;
    printf("\nTotal electic = %.2f",pw.total_ele);
    getch();
}

int calculatorpowreqTOU(float peak,float peak2,float offpeak,float offpeak2,float powre,float powreq,float rp)
{
    rp = calreactivepower(powre,rp);
    pw.total_ele = (peak*peak2)+(offpeak*offpeak2)+(powre*powreq)+pw.service;
    printf("\nElectic energe = %.2f",(peak*peak2)+(offpeak*offpeak2)+(powre*powreq));
    printf("\nService = %.2f",pw.service);
    printf("\nReactive power = %.2f",rp);
    printf("\nTotal electic = %.2f",pw.total_ele);
    ft = (peak+offpeak)*ft;
    printf("\nElectic energe * Ft = %.2f",ft);
    pw.vat = (pw.total_ele+ft+rp)*7/100;
    printf("\nVAT = %.2f",pw.vat);
    pw.total_ele = pw.total_ele+ft+rp+pw.vat;
    printf("\nTotal electic = %.2f",pw.total_ele);
    getch();
}

int calculatorpowreqTOD(float peak,float peak2,float partial,float partial2,float ele,float ele2,float rp)
{
    float x;
    x = peak+partial;
    rp = calreactivepower(x,rp);
    pw.total_ele = (peak*peak2)+(partial*partial2)+(ele*ele2)+pw.service;
    printf("\nElectic energe = %.2f",(peak*peak2)+(partial*partial2)+(ele*ele2));
    printf("\nService = %.2f",pw.service);
    printf("\nReactive power = %.2f",rp);
    printf("\nTotal electic = %.2f",pw.total_ele);
    ft = (ele)*ft;
    printf("\nElectic energe * Ft = %.2f",ft);
    pw.vat = (pw.total_ele+ft+rp)*7/100;
    printf("\nVAT = %.2f",pw.vat);
    pw.total_ele = pw.total_ele+ft+rp+pw.vat;
    printf("\nTotal electic = %.2f",pw.total_ele);
    getch();
}

int calnonprofit(float ele, int x)
{
    pw.eleft = ele;
    if (x == 1)
    {
        pw.total = ele*3.4149;
    }
    else if (x == 2)
    {
        pw.total = ele*3.5849;
    }
    else if (x == 3)
    {
        if (ele >= 0 && ele <= 10)
        {
            pw.total = ele*2.8013;
        }
        else
        {
            pw.total = 10*2.8013;
            ele = ele - 10;
            ele = ele*3.8919;
            pw.total = pw.total*ele;
        }
    }
    pw.total_ele = pw.total+pw.service;
    printf("\nElectic energe = %.2f",pw.total);
    printf("\nService = %.2f",pw.service);
    printf("\nTotal electic = %.2f",pw.total_ele);
    ft =  pw.eleft*ft;
    printf("\nElectic energe * Ft = %.2f",ft);
    pw.vat = (pw.total_ele+ft)*7/100;
    printf("\nVAT = %.2f",pw.vat);
    pw.total_ele = pw.total_ele+ft+pw.vat;
    printf("\nTotal electic = %.2f",pw.total_ele);
    getch();
}

int personal(float ele,int x) //user personal
{
    if (x == 1) // user type use electic < 150
    {
        pw.service = 8.19;
        calculator(ele,x,0);
    }
    else if (x == 2) // user type use electic > 150
    {
        pw.service = 24.62;
        calculator(ele,x,0);
    }
    else
        printf("\nERROR");
}

int personalTOU(float peak,float offpeak,int x) //presonal tou user
{
    if (x == 1) //Voltage 22-33 kV
    {
        pw.service = 312.24;
        calculatorTOU(peak,5.1135,offpeak,2.6037);
    }
    else if (x == 2) //Voltage less than 22 kV
    {
        pw.service = 24.62;
        calculatorTOU(peak,5.7982,offpeak,2.6369);
    }
    else
        printf("\nERROR");
}

int smallbusiness(float ele,int x) //small business user
{
    if (x == 1) //Voltage 22-33 kV
    {
        pw.service = 312.24;
        calculator(ele,0,3.9086);
    }
    else if (x == 2) //Voltage less than 22 kV
    {
        pw.service = 33.29;
        calculator(ele,x,0);
    }
    else
        printf("\nERROR");
}

int smallbusinessTOU(float peak,float offpeak,int x) //small business tou user
{
    if (x == 1) //Voltage 22-33 kV
    {
        pw.service = 312.24;
        calculatorTOU(peak,5.1135,offpeak,2.6037);
    }
    else if (x == 2) //Voltage less than 22 kV
    {
        pw.service = 33.29;
        calculatorTOU(peak,5.7982,offpeak,2.6369);
    }
    else
        printf("\nERROR");
}

int mediumbusiness(float ele,float pr,float rp,int x)
{
    pw.service = 312.24;
    if (x == 1) //Voltage more than 69 kV
    {
        calculatorpowreq(ele,3.1097,pr,175.70,rp);
    }
    else if (x == 2) //Voltage 22-33 kV
    {
        calculatorpowreq(ele,3.1471,pr,196.26,rp);
    }
    else if (x == 3) //Voltage more less 22 kV
    {
        calculatorpowreq(ele,3.1751,pr,221.50,rp);
    }
    
    else
        printf("\nERROR");
}

int mediumbusinessTOU(float peak,float offpeak,float pr,float rp,int x)
{
    pw.service = 312.24;
    if (x == 1) //Voltage more than 69 kV
    {
        calculatorpowreqTOU(peak,4.1025,offpeak,2.5849,pr,74.14,rp);
    }
    else if (x == 2) //Voltage 22-33 kV
    {
        calculatorpowreqTOU(peak,4.1839,offpeak,2.6037,pr,132.93,rp);
    }
    else if (x == 3) //Voltage more less 22 kV
    {
        calculatorpowreqTOU(peak,4.3297,offpeak,2.6369,pr,210.00,rp);
    }
    else
        printf("\nERROR");
}

int bigbusiness(float peak,float partial,float ele,float rp,int x)
{
    pw.service = 312.24;
    if(partial > peak)
    {
    	partial = partial - peak;
	}
	else
		partial = 0;
		
    if (x == 1) //Voltage more than 69 kV
    {
        calculatorpowreqTOD(peak,224.30,partial,29.91,ele,3.1097,rp);
    }
    else if (x == 2) //Voltage 22-33 kV
    {
        calculatorpowreqTOD(peak,285.05,partial,58.88,ele,3.1471,rp);
    }
    else if (x == 3) //Voltage more less 22 kV
    {
        calculatorpowreqTOD(peak,332.71,partial,68.22,ele,3.1751,rp);
    }
    else
        printf("\nERROR");
}

int specificbusiness(float ele,float pr,float rp,int x)
{
    pw.service = 312.24;
    if (x == 1) //Voltage more than 69 kV
    {
        calculatorpowreq(ele,3.1097,pr,220.56,rp);
    }
    else if (x == 2) //Voltage 22-33 kV
    {
        calculatorpowreq(ele,3.1471,pr,256.07,rp);
    }
    else if (x == 3) //Voltage more less 22 kV
    {
        calculatorpowreq(ele,3.1751,pr,276.64,rp);
    }
    
    else
        printf("\nERROR");
}

int nonprofit(float ele,int x)
{
    if(x == 1 || x == 2)
    {
        pw.service = 312.24;
        calnonprofit(ele,x);
    }
    else if (x == 3)
    {
        pw.service = 20;
        calnonprofit(ele,x);
    }
    
    else
        printf("\nERROR");
}

int pumpingwater(float ele)
{
    pw.service = 115.16;
    pw.eleft = ele;
    if (ele >= 0 && ele <= 100)
    {
        pw.total = ele*2.0889;
    }
    else
    {
        pw.total = 100*2.0889;
        ele = ele-100;
        ele = ele*3.2405;
        pw.total = pw.total+ele;
    }
    pw.total_ele = pw.total+pw.service;
    printf("\nElectic energe = %.2f",pw.total);
    printf("\nService = %.2f",pw.service);
    printf("\nTotal electic = %.2f",pw.total_ele);
    ft =  pw.eleft*ft;
    printf("\nElectic energe * Ft = %.2f",ft);
    pw.vat = (pw.total_ele+ft)*7/100;
    printf("\nVAT = %.2f",pw.vat);
    pw.total_ele = pw.total_ele+ft+pw.vat;
    printf("\nTotal electic = %.2f",pw.total_ele);
}

int main()//เลือก
{
    int type;
    float electic,electic2,powerre,reactivepower;
    show("Electricity calculation program",40,0);
    printf("1.Personal\n2.Personal TOU\n3.Small Business\n4.Small Business TOU\n5.Middle Business\n6.Medium Business TOU\n7.Big Business TOD\n8.Big Business TOU\n9.Specific Business TOU\n10.Specific Business not have meters\n11.Non-profit organization\n12.Non-profit organization TOU\n13.Pumping water for agriculture\n14.Pumping water for agriculture TOU\n15.Temporary electricity\n");
    printf("\nEnter type electric : ");
    scanf("%d",&type);
    switch (type)
    {
    case 1:
        show("Personal TOU",40,0);
        printf("1.Use electic less than 150\n2.Use electic more than 150\n");
        printf("\nEnter type user : ");
        scanf("%d",&type);
        printf("Enter amout of electric : ");
        scanf("%f",&electic);
        personal(electic,type);
        break;

    case 2:
        show("Personal TOU",40,0);
        printf("1.Voltage 22-33 kV\n2.Voltage less than 22 kV\n");
        printf("\nEnter type user : ");
        scanf("%d",&type);
        printf("Enter amout of electric (Peak): ");
        scanf("%f",&electic);
        printf("Enter amout of electric (Off Peak): ");
        scanf("%f",&electic2);
        personalTOU(electic,electic2,type);
        break;

    case 3:
        show("Small Business",40,0);
        printf("1.Voltage 22-33 kV\n2.Voltage less than 22 kV\n");
        printf("\nEnter type user : ");
        scanf("%d",&type);
        printf("Enter amout of electric : ");
        scanf("%f",&electic);
        smallbusiness(electic,type);
        break;

    case 4:
        show("Small Business TOU",40,0);
        printf("1.Voltage 22-33 kV\n2.Voltage less than 22 kV\n");
        printf("\nEnter type user : ");
        scanf("%d",&type);
        printf("Enter amout of electric (Peak): ");
        scanf("%f",&electic);
        printf("Enter amout of electric (Off Peak): ");
        scanf("%f",&electic2);
        smallbusinessTOU(electic,electic2,type);
        break;

    case 5:
        show("Middle Business",40,0);
        printf("\n1.Voltage more than 69 kV\n2.Voltage 22-33 kV\n3.Voltage less than 22 kV\n");
        printf("\nEnter type user : ");
        scanf("%d",&type);
        printf("Enter Demand charge : ");
        scanf("%f",&powerre);
        printf("Enter amout of electric : ");
        scanf("%f",&electic);
        printf("Enter Reactive power : ");
        scanf("%f",&reactivepower);
        mediumbusiness(electic,powerre,reactivepower,type);
        break; 

    case 6:
        show("Middle Business TOU",40,0);
        printf("\n1.Voltage more than 69 kV\n2.Voltage 22-33 kV\n3.Voltage less than 22 kV\n");
        printf("\nEnter type user : ");
        scanf("%d",&type);
        printf("Enter Demand charge Peak : ");
        scanf("%f",&powerre);
        printf("Enter amout of electric (Peak): ");
        scanf("%f",&electic);
        printf("Enter amout of electric (Off Peak): ");
        scanf("%f",&electic2);
        printf("Enter Reactive power : ");
        scanf("%f",&reactivepower);
        mediumbusinessTOU(electic,electic2,powerre,reactivepower,type);
        break;

    case 7:
        show("Big Business TOD",40,0);
        printf("\n1.Voltage more than 69 kV\n2.Voltage 22-33 kV\n3.Voltage less than 22 kV\n");
        printf("\nEnter type user : ");
        scanf("%d",&type);
        printf("Enter Demand charge Peak : ");
        scanf("%f",&powerre);
        printf("Enter Demand charge Partial : ");
        scanf("%f",&electic);
        printf("Enter amout of electric : ");
        scanf("%f",&electic2);
        printf("Enter Reactive power : ");
        scanf("%f",&reactivepower);
        bigbusiness(powerre,electic,electic2,reactivepower,type);
        break;

    case 8:
        show("Big Business TOU",40,0);
        printf("\n1.Voltage more than 69 kV\n2.Voltage 22-33 kV\n3.Voltage less than 22 kV\n");
        printf("\nEnter type user : ");
        scanf("%d",&type);
        printf("Enter Demand charge Peak : ");
        scanf("%f",&powerre);
        printf("Enter amout of electric (Peak): ");
        scanf("%f",&electic);
        printf("Enter amout of electric (Off Peak): ");
        scanf("%f",&electic2);
        printf("Enter Reactive power : ");
        scanf("%f",&reactivepower);
        mediumbusinessTOU(electic,electic2,powerre,reactivepower,type);
        break;

    case 9:
        show("Specific Business TOU",40,0);
        printf("\n1.Voltage more than 69 kV\n2.Voltage 22-33 kV\n3.Voltage less than 22 kV\n");
        printf("\nEnter type user : ");
        scanf("%d",&type);
        printf("Enter Demand charge Peak : ");
        scanf("%f",&powerre);
        printf("Enter amout of electric (Peak): ");
        scanf("%f",&electic);
        printf("Enter amout of electric (Off Peak): ");
        scanf("%f",&electic2);
        printf("Enter Reactive power : ");
        scanf("%f",&reactivepower);
        mediumbusinessTOU(electic,electic2,powerre,reactivepower,type);
        break;

    case 10:
        show("Specific Business not have meters",40,0);
        printf("\n1.Voltage more than 69 kV\n2.Voltage 22-33 kV\n3.Voltage less than 22 kV\n");
        printf("\nEnter type user : ");
        scanf("%d",&type);
        printf("Enter Demand charge : ");
        scanf("%f",&powerre);
        printf("Enter amout of electric : ");
        scanf("%f",&electic);
        printf("Enter Reactive power : ");
        scanf("%f",&reactivepower);
        specificbusiness(electic,powerre,reactivepower,type);
        break;

    case 11:
        show("Non-profit organization",40,0);
        printf("\n1.Voltage more than 69 kV\n2.Voltage 22-33 kV\n3.Voltage less than 22 kV\n");
        printf("\nEnter type user : ");
        scanf("%d",&type);
        printf("Enter amout of electric : ");
        scanf("%f",&electic);
        nonprofit(electic,type);
        break;

    case 12:
        show("Non-profit organization TOU",40,0);
        printf("\n1.Voltage more than 69 kV\n2.Voltage 22-33 kV\n3.Voltage less than 22 kV\n");
        printf("\nEnter type user : ");
        scanf("%d",&type);
        printf("Enter Demand charge Peak : ");
        scanf("%f",&powerre);
        printf("Enter amout of electric (Peak): ");
        scanf("%f",&electic);
        printf("Enter amout of electric (Off Peak): ");
        scanf("%f",&electic2);
        printf("Enter Reactive power : ");
        scanf("%f",&reactivepower);
        mediumbusinessTOU(electic,electic2,powerre,reactivepower,type);
        break;

    case 13:
        show("Pumping water for agriculture",40,0);
        printf("\nEnter amout of electric : ");
        scanf("%f",&electic);
        pumpingwater(electic);
        break;

    case 14:
        show("Pumping water for agriculture TOU",40,0);
        printf("\n1.Voltage 22-33 kV\n2.Voltage less than 22 kV\n");
        printf("\nEnter type user : ");
        scanf("%d",&type);
        printf("Enter Demand charge Peak : ");
        scanf("%f",&powerre);
        printf("Enter amout of electric (Peak): ");
        scanf("%f",&electic);
        printf("Enter amout of electric (Off Peak): ");
        scanf("%f",&electic2);
        printf("Enter Reactive power : ");
        scanf("%f",&reactivepower);
        ++type;
        mediumbusinessTOU(electic,electic2,powerre,reactivepower,type);
        break;

    case 15:
        show("Temporary electricity",40,0);
        printf("\nEnter amout of electric : ");
        scanf("%f",&electic);
        calculator(electic,0,6.8025);
        break;
    default:
        break;
    }
}
