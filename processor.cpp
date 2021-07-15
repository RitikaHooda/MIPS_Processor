#include <iostream>
#include <string.h>
#include <fstream>
#include <bitset>
#include <cmath>
#include <sstream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

#define ull unsigned long long int
#define ADD 0
#define SUB 1
#define SLL 2
#define SRL 3
#define LW 4
#define SW 5
#define BEQ 6
#define BNE 7
#define BLEZ 8
#define BGTZ 9
#define J 10
#define JAL 11
#define JR 12
#define HLT 13
#define R 14
#define $zero 0
#define $at 1
#define $v0 2
#define $v1 3
#define $k0 26
#define $k1 27
#define $gp 28
#define $sp 29
#define $fp 30
#define $a0 4
#define $a1 5
#define $a2 6
#define $a3 7
#define $s0 16
#define $s1 17
#define $s2 18
#define $s3 19
#define $s4 20
#define $s5 21
#define $s6 22
#define $s7 23
#define $t0 8
#define $t1 9
#define $t2 10
#define $t3 11
#define $t4 12
#define $t5 13
#define $t6 14
#define $t7 15
#define $t8 24
#define $t9 25
#define $ra 31
#define MemSize 4096
#define ImemSize 1024

char flip(char c) {return (c == '0')? '1': '0';} 
int randomwithProb(double p){
double rnDouble= (double) rand() / RAND_MAX;
return rnDouble >p ;}
string TwosComplement(string bin) 
{ 
    int n = bin.length(); 
    int i; 
  
    string ones, twos; 
    ones = twos = ""; 
  
    //  for ones complement flip every bit 
    for (i = 0; i < n; i++) 
      {  ones += flip(bin[i]);} 
  
    //  for two's complement go from right to left in 
    //  ones complement and if we get 1 make, we make 
    //  them 0 and keep going left when we get first 
    //  0, make that 1 and go out of loop 
    twos = ones; 
    for (i = n - 1; i >= 0; i--) 
    { 
        if (ones[i] == '1') 
            twos[i] = '0'; 
        else
        { 
            twos[i] = '1'; 
            break; 
        } 
    } 
  
    // If No break : all are 1  as in 111  or  11111; 
    // in such case, add extra 1 at beginning 
    if (i == -1) 
        twos = '1' + twos; 
  
   
return twos; 
} 
string makesize(string s,int size)
{
	int n=s.length();	
	string rep="";
	for(int i=0;i<size-n;i++)
	{
		rep+="0";
	}
	rep.append(s);
	return rep;

}

string decToBinary(int N) 
{ 
  
    // To store the binary number 
    int neg=0;
	if(N<0){neg=1;N=-N;}
    ull B_Number = 0; 
    int cnt = 0; 
    while (N != 0) { 
        int rem = N % 2; 
        ull c = pow(10, cnt); 
        B_Number += rem * c; 
        N /= 2; 
  
        // Count used to store exponent value 
        cnt++; 
    }//cout<<B_Number<<"it is"<<endl;
	
    return to_string(B_Number); 
}  


int binaryToDecimal(string s) 
{ 
  
    int dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
  
    string temp =s; int done=1;
    while (temp.length()>0) { 
        int last_digit =stoi(temp.substr(temp.length()-1,temp.length())); 
        temp = temp.substr(0,temp.length()-1); 
        dec_value += last_digit * base; 
        base = base * 2; 
    } 
    return dec_value; 
} 



int match(string s)
{
	if(s=="$zero")
	{
		return $zero;
	}else
	if(s=="$at")
	{
		return $at;
	}else
	if(s=="$v0")
	{
		return $v0;
	}else
	if(s=="$v1")
	{
		return $v1;
	}else
	if(s=="$a0")
	{
		return $a0;
	}else
	if(s=="$a1")
	{
		return $a1;
	}else
	if(s=="$a2")
	{
		return $a2;
	}else
	if(s=="$a3")
	{
		return $a3;
	}else
	if(s=="$t0")
	{
		return $t0;
	}else
	if(s=="$t1")
	{
		return $t1;
	}else
	if(s=="$t2")
	{
		return $t2;
	}else
	if(s=="$t3")
	{
		return $t3;
	}else
	if(s=="$t4")
	{
		return $t4;
	}else
	if(s=="$t5")
	{
		return $t5;
	}else
	if(s=="$t6")
	{
		return $t6;
	}else
	if(s=="$t7")
	{
		return $t7;
	}else
	if(s=="$t8")
	{
		return $t8;
	}else
	if(s=="$t9")
	{
		return $t9;
	}else
	if(s=="$s0")
	{
		return $s0;
	}else
	if(s=="$s1")
	{
		return $s1;
	}else
	if(s=="$s2")
	{
		return $s2;
	}else
	if(s=="$s3")
	{
		return $s3;
	}else
	if(s=="$s4")
	{
		return $s4;
	}else
	if(s=="$s5")
	{
		return $s5;
	}else
	if(s=="$s6")
	{
		return $s6;
	}else
	if(s=="$s7")
	{
		return $s7;
	}else
	if(s=="$ra")
	{
		return $ra;
	}else
	if(s=="$gp")
	{
		return $gp;
	}else
	if(s=="$fp")
	{
		return $fp;
	}else
	if(s=="$sp")
	{
		return $sp;
	}else
	if(s=="$k0")
	{
		return $k0;
	}else
	if(s=="$zero")
	{
		return $k1;
	}
return 0;
}

int get(string n)
{
	int neg=0;
	if (n.at(0)=='1')
	{
		neg=1;n=TwosComplement(n);
	}
	int s=binaryToDecimal(n);
	if(neg==1)
	{
		s=-s;
	}
return s;
}

string convertTo32bit(string line)
{
	string parts[4];
	istringstream iss(line);
	int i=0;
	string word;
	while(iss>>word)
	{
		parts[i]=word;
		i++;
	}
	string opcode,func,rs,rt,rd,addr,offset,shamt; 
	int rsint,rtint,rdint,shamtint;
	if(parts[0]=="add")
	{
		opcode="000000"; func="100000";
		rdint=match(parts[1].substr(0,parts[1].length()-1));
		rtint=match(parts[2].substr(0,parts[2].length()-1));
		rsint=match(parts[3].substr(0,parts[3].length()));
		shamt="00000";
		rd=makesize(decToBinary(rdint),5);
		rs=makesize(decToBinary(rsint),5);
		rt=makesize(decToBinary(rtint),5);
		opcode.append(rs);opcode.append(rt);
		opcode.append(rd);opcode.append(shamt);
		opcode.append(func);
		//cout<<opcode<<endl;
	}else
	if(parts[0]=="sub")
	{
		opcode="000000"; func="100010";
		rdint=match(parts[1].substr(0,parts[1].length()-1));
		rtint=match(parts[2].substr(0,parts[2].length()-1));
		rsint=match(parts[3].substr(0,parts[3].length()));
		shamt="00000";
		rd=makesize(decToBinary(rdint),5);
		rs=makesize(decToBinary(rsint),5);
		rt=makesize(decToBinary(rtint),5);
		opcode.append(rs);opcode.append(rt);
		opcode.append(rd);opcode.append(shamt);
		opcode.append(func);
	}else
	if(parts[0]=="sll")
	{
		
		opcode="000000"; func="000000";
		rdint=match(parts[1].substr(0,parts[1].length()-1));
		rtint=match(parts[2].substr(0,parts[2].length()-1));
		shamtint=stoi(parts[3]);
		int neg=0;
		if(shamtint<0){neg=1;shamtint=-shamtint;}
		rs="00000";
		rd=makesize(decToBinary(rdint),5);
		shamt=makesize(decToBinary(shamtint),5);
		if(neg==1)
		{
			shamt=TwosComplement(shamt);
		}

		rt=makesize(decToBinary(rtint),5);
		opcode.append(rs);opcode.append(rt);
		opcode.append(rd);opcode.append(shamt);
		opcode.append(func);
		//cout<<opcode<<endl;
		
	}else
	if(parts[0]=="srl")
	{
		opcode="000000"; func="000010";
		rdint=match(parts[1].substr(0,parts[1].length()-1));
		rtint=match(parts[2].substr(0,parts[2].length()-1));
		shamtint=stoi(parts[3]);
		int neg=0;
		if(shamtint<0){neg=1;shamtint=-shamtint;}
		rs="00000";
		rd=makesize(decToBinary(rdint),5);
		shamt=makesize(decToBinary(shamtint),5);
		if(neg==1)
		{
			shamt=TwosComplement(shamt);
		}
		rt=makesize(decToBinary(rtint),5);
		opcode.append(rs);opcode.append(rt);
		opcode.append(rd);opcode.append(shamt);
		opcode.append(func);
		//cout<<opcode<<endl;
	}else
	if(parts[0]=="lw")
	{
		opcode="100011"; 
		//rdint=match(parts[1].substr(0,3));
		stringstream p(parts[2]);string tokens[2];int k=0;
		string s;
		while(getline(p,s,'('))
		{
			tokens[k]=s;k++;
		}
		int offsetint=stoi(tokens[0]);
		int neg=0;//cout<<tokens[0]<<endl;
		if(offsetint<0){neg=1;offsetint=-offsetint;}		
		offset=makesize(decToBinary(offsetint),16);
		if(neg==1)
		{
			offset=TwosComplement(offset);
		}
		rtint=match(parts[1].substr(0,parts[1].length()-1));
		rsint=match(tokens[1].substr(0,tokens[1].length()-1));
		rs=makesize(decToBinary(rsint),5);
		rt=makesize(decToBinary(rtint),5);
		opcode.append(rs);opcode.append(rt);
		opcode.append(offset);	
		//cout<<opcode<<endl;
	}else
	if(parts[0]=="sw")
	{
		opcode="101011"; 
		//rdint=match(parts[1].substr(0,3));
		stringstream p(parts[2]);string tokens[2];int k=0;
		string s;
		while(getline(p,s,'('))
		{
			tokens[k]=s;k++;
		}
		int offsetint=stoi(tokens[0]);
		int neg=0;//cout<<tokens[0]<<endl;
		if(offsetint<0){neg=1;offsetint=-offsetint;}		
		offset=makesize(decToBinary(offsetint),16);
		if(neg==1)
		{
			offset=TwosComplement(offset);
		}
		rtint=match(parts[1].substr(0,parts[1].length()-1));
		rsint=match(tokens[1].substr(0,tokens[1].length()-1));
		rs=makesize(decToBinary(rsint),5);
		rt=makesize(decToBinary(rtint),5);
		opcode.append(rs);opcode.append(rt);
		opcode.append(offset);
		//cout<<opcode<<endl;
	}else
	if(parts[0]=="bne")
	{
		opcode="000101"; 
		//rdint=match(parts[1].substr(0,3));
		 int offsetint=stoi(parts[3]);
		int neg=0;//cout<<tokens[0]<<endl;
		if(offsetint<0){neg=1;offsetint=-offsetint;}		
		offset=makesize(decToBinary(offsetint),16);
		if(neg==1)
		{
			offset=TwosComplement(offset);
		}
		rtint=match(parts[2].substr(0,parts[2].length()-1));
		rsint=match(parts[1].substr(0,parts[1].length()-1));
		rs=makesize(decToBinary(rsint),5);
		rt=makesize(decToBinary(rtint),5);
		opcode.append(rs);opcode.append(rt);
		opcode.append(offset);
		//cout<<opcode<<endl;
	}else
	if(parts[0]=="beq")
	{
		opcode="000100"; int offsetint=stoi(parts[3]);
		int neg=0;//cout<<tokens[0]<<endl;
		if(offsetint<0){neg=1;offsetint=-offsetint;}		
		offset=makesize(decToBinary(offsetint),16);
		if(neg==1)
		{
			offset=TwosComplement(offset);
		}
		rtint=match(parts[2].substr(0,parts[2].length()-1));
		rsint=match(parts[1].substr(0,parts[1].length()-1));
		rs=makesize(decToBinary(rsint),5);
		rt=makesize(decToBinary(rtint),5);
		opcode.append(rs);opcode.append(rt);
		opcode.append(offset);
		//cout<<opcode<<endl;
	}else
	if(parts[0]=="blez")
	{
		opcode="000110"; 
		//rdint=match(parts[1].substr(0,3));
		 int offsetint=stoi(parts[2]);
		int neg=0;//cout<<tokens[0]<<endl;
		if(offsetint<0){neg=1;offsetint=-offsetint;}		
		offset=makesize(decToBinary(offsetint),16);
		if(neg==1)
		{
			offset=TwosComplement(offset);
		}
		rsint=match(parts[1].substr(0,parts[1].length()-1));
		rs=makesize(decToBinary(rsint),5);
		rt=makesize(decToBinary(rtint),5);
		opcode.append(rs);opcode.append(rt);
		opcode.append(offset);
		//cout<<opcode<<endl;
	}else
	if(parts[0]=="bgtz")
	{
		opcode="000111"; 
		//rdint=match(parts[1].substr(0,3));
		 int offsetint=stoi(parts[2]);
		int neg=0;//cout<<tokens[0]<<endl;
		if(offsetint<0){neg=1;offsetint=-offsetint;}		
		offset=makesize(decToBinary(offsetint),16);
		if(neg==1)
		{
			offset=TwosComplement(offset);
		}
		rsint=match(parts[1].substr(0,parts[1].length()-1));
		rs=makesize(decToBinary(rsint),5);
		rt=makesize(decToBinary(rtint),5);
		opcode.append(rs);opcode.append(rt);
		opcode.append(offset);
		//cout<<opcode<<endl;
	}else
	if(parts[0]=="j")
	{
		opcode="000010"; 
		//rdint=match(parts[1].substr(0,3));
		int offsetint=stoi(parts[1]);
		int neg=0;
		if(offsetint<0){neg=1;offsetint=-offsetint;}		
		offset=makesize(decToBinary(offsetint),26);
		if(neg==1)
		{
			offset=TwosComplement(offset);
		}
		opcode.append(offset);
		//cout<<opcode<<endl;
	}else
	if(parts[0]=="jal")
	{
		opcode="000011"; 
		//rdint=match(parts[1].substr(0,3));
		int offsetint=stoi(parts[1]);
		int neg=0;
		if(offsetint<0){neg=1;offsetint=-offsetint;}		
		offset=makesize(decToBinary(offsetint),26);
		if(neg==1)
		{
			offset=TwosComplement(offset);
		}
		opcode.append(offset);
		//cout<<opcode<<endl;
	}else
	if(parts[0]=="jr")
	{
		opcode="001000"; 
		//rdint=match(parts[1].substr(0,3));
		int offsetint=0;
		int neg=0;
		if(offsetint<0){neg=1;offsetint=-offsetint;}		
		offset=makesize(decToBinary(offsetint),26);
		if(neg==1)
		{
			offset=TwosComplement(offset);
		}
		opcode.append(offset);
		//cout<<opcode<<endl;
	}
return opcode;
}


class RF
{
public:
    vector<bitset<32> >Registers;
    ofstream rfout;
    bitset<32> ReadData1, ReadData2,ReadData3,ra;
    RF()
    {//cout<<"startRF"<<endl;
        Registers.resize(32);
        Registers[0] = bitset<32> (0);
	Registers[$s1]=bitset<32> (1);
	Registers[$a1]=bitset<32> (1);
	Registers[$t0]=bitset<32> (3);
	//Registers[31]=bitset<32> (3);
    }

    bitset<32> getra()
    {
	return Registers[31];
    }

    void ReadWrite(bitset<5> RdReg1, bitset<5> RdReg2, bitset<5> WrtReg, bitset<32> WrtData, bitset<1> WrtEnable)
    {
        // implement the function by you.
            
            ReadData1 = Registers[RdReg1.to_ulong()];   // perform read operation
            ReadData2 = Registers[RdReg2.to_ulong()];
	    ReadData3 = Registers[WrtReg.to_ulong()];

         if(WrtEnable.to_ulong() == 1){
           
            Registers[WrtReg.to_ulong()] = WrtData;    // perform write operation
        }
    }

    void OutputRF()
    {
        if (rfout.is_open())
        {
            rfout<<"A state of RF:"<<endl;
            for (int j = 0; j<32; j++)
            {
                rfout << Registers[j]<<endl;
            }
        }
        else cout<<"Unable to open file";
    }
    
    void closeWrite(){
	rfout.close();
    }

    void openwrite(){
	rfout.open("RFresult.txt");
    }
};

class ALU
{
public:
    bitset<32> ALUresult;
    bitset<32> ALUOperation (string ALUOP, bitset<32> oprand1, bitset<32> oprand2)
    {    // implement the ALU operations by you.
        unsigned long result;

        if(ALUOP == "addu"){
            result = oprand1.to_ulong() + oprand2.to_ulong(); // addu operation
        }
        else if(ALUOP == "subu"){
            result = oprand2.to_ulong() - oprand1.to_ulong(); // subu operation
        }
        else if(ALUOP == "and"){
            result = oprand1.to_ulong() & oprand2.to_ulong(); // and operation
        }
        else if(ALUOP == "or"){
            result = oprand1.to_ulong() | oprand2.to_ulong(); // or operation
        }
        else if(ALUOP == "nor"){
            result = ~(oprand1.to_ulong() | oprand2.to_ulong()); // nor operation
        }
	else if(ALUOP == "slt"){
            result = ~(oprand1.to_ulong() < oprand2.to_ulong()); // slt operation
        }
	else if(ALUOP == "mult"){
            result = (oprand1.to_ulong()*pow(2,oprand2.to_ulong()));//cout<<oprand2.to_ulong()<<"sll"<<endl; // mult(sll) operation
        }
	else if(ALUOP == "div"){
            result = (oprand1.to_ulong()/pow(2,oprand2.to_ulong())); // slt operation
        }

        bitset<32> res((int)result);
        ALUresult = res;
        return ALUresult;
    }
};

class INSMem
{
public:
    bitset<32> Instruction;int count;
    INSMem()
    {       IMem.resize(ImemSize);
        ifstream imem;
        string line;
        int i=0;count=0;
        imem.open("instructions.txt");
        if (imem.is_open())
        {
            while (getline(imem,line))
            {
		string instr=convertTo32bit(line);
                IMem[i] = bitset<32>(instr);
                i++;count++;
            }
        }
        else cout<<"Unable to open file";
        imem.close();
	IMem[i]=bitset<32>(4294967295);
    }

    int getsize()
    {
	return count;
    }


    bitset<32> ReadMemory (bitset<32> ReadAddress)
    {    // implement by you. (Read the byte at the ReadAddress and the following three byte).
        unsigned long count = ReadAddress.to_ulong();
        int index = (int)count;
        Instruction = IMem[index];

        return Instruction;
    }
private:
    vector<bitset<32> > IMem;

};


class DataMem
{
public:
    vector<bitset<32> > DMem;
    bitset<32> readdata;
    ofstream dmemout;
    DataMem()
    {
        DMem.resize(MemSize);
        ifstream dmem;
        string line;
        int i=0;
        dmem.open("dmem.txt");
        if (dmem.is_open())
        {
            while (getline(dmem,line))
            {
                DMem[i] = bitset<32>(line);
                i++;
            }
        }
        else cout<<"Unable to open file";
        dmem.close();
    }

    bitset<32> MemoryAccess (bitset<32> Address, bitset<32> WriteData, bitset<1> readmem, bitset<1> writemem)
    {
        unsigned long count = Address.to_ulong();
        int index = (int) count;
	//cout<<index<<endl;
        if((readmem.to_ulong() == 1) && (writemem.to_ulong() == 0)) {
            readdata = DMem[index];
        }

        else if((readmem.to_ulong() == 0) && (writemem.to_ulong() == 1)){
                DMem[index] =  WriteData;
        }
        return readdata;
    }

    void OutputDataMem()
    {
        
        dmemout.open("dmemresult.txt");
        if (dmemout.is_open())
        {
            for (int j = 0; j<250; j++)
            {
                dmemout << DMem[j]<<endl;
            }
        }
        else cout<<"Unable to open file";
	dmemout.close();
    }
   

};

int TypeofInstruction(string opcode,string func){
    if(opcode == "000000")
    {
	if (func=="100000") return 0;
	else if ( func=="100010") return 1;
	else if ( func=="000000") return 2;
	else if ( func=="000010") return 3;
    }
    else if(opcode == "000010") return 10;
    else if(opcode == "000011") return 11;
    else if(opcode == "001000") return 12;
    else if(opcode == "111111") return 13;
    else if(opcode == "000100") return 6;
    else if(opcode == "000101") return 7;
    else if(opcode == "000110") return 8;
    else if(opcode == "000111") return 9;
    else if(opcode == "100011") return 4;
    else if(opcode == "101011") return 5;
    else return -1;
}

bitset<32> calc_PC(bitset<32> &programCounter)
{
      programCounter = bitset<32> (programCounter.to_ulong()+1);
      return programCounter;
}

class Processor{
	RF myRF;
        ALU myALU;
        INSMem myInsMem;
        DataMem myDataMem;

        bitset<32> programCounter = bitset<32> (0);
	bitset<32> instruction;

	/*
		Private Functions: 
			Internal Implementations for Pipeline Stages Logic
	*/

	/* Stage 1: Instruction Fetch & Increment PC */
	void instrFetch(){
		instruction = myInsMem.ReadMemory(programCounter);
		programCounter=bitset<32>(programCounter.to_ulong()+ 1);
	}

	/* Stage 2: Decode & Operand Fetch */
	void decodeAndOperandFetch(bitset<32> instruction, int &opcode,string *regIds,bitset<32> *regVals, bitset<32> &ImmVal,bitset<32> &Addr){
		string opc = instruction.to_string().substr(0,6);
		string func= instruction.to_string().substr(26,6);
		if(instruction==bitset<32> (0)){ opcode=HLT;}else{
		opcode=TypeofInstruction(opc,func);
		regIds[0] = instruction.to_string().substr(6,5);
		regIds[1] = instruction.to_string().substr(11,5);
		regIds[2] = instruction.to_string().substr(16,5);
		
		myRF.ReadWrite(bitset<5>(regIds[0]),bitset<5>(regIds[1]),bitset<5>(regIds[2]),NULL,0);
		regVals[0] = myRF.ReadData1;
		regVals[1] = myRF.ReadData2;
		regVals[2] = myRF.ReadData3;
		//cout<<regVals[1]<<"decode"<<endl;
		ImmVal = bitset<32>(instruction.to_string().substr(16,16));
		Addr = bitset<32>(instruction.to_string().substr(6,26));}
	}

	/* Stage 3: Execute */
	void execute(bitset<32> instruction,int opcode, bitset<32> *regVals,bitset<32> ImmVal,bitset<32> Addr,bitset<32> currPC,bitset<32> &ALUResult,bitset<32> &loc,bitset<32> &nextPC){
		// Actual Execution
		bitset<32> shamt=bitset<32> (instruction.to_string().substr(21,5));
		bool isneg=false;
		switch(opcode){
			case ADD: 	ALUResult = myALU.ALUOperation("addu",regVals[0],regVals[1]);//myRF.OutputRF();cout<<ALUResult<<endl;
					  	break;
			
			case SUB:	ALUResult =myALU.ALUOperation("subu",regVals[0],regVals[1]);
					  	break;

			case SLL: 	ALUResult = myALU.ALUOperation("mult",regVals[1],shamt);//cout<<regVals[1]<<"SLLLLLLLL"<<endl;
					  	break;
			
			case SRL:	ALUResult =myALU.ALUOperation("div",regVals[1],shamt);
					  	break;

			case LW:	loc = myALU.ALUOperation("addu",regVals[0],ImmVal);//cout<<loc<<endl;
					  	break;

			case SW:	loc = myALU.ALUOperation("addu",regVals[0],ImmVal);
						ALUResult = regVals[1];//cout<<regVals[1]<<"swwwwwwwwwwwwwwwwwwwwwwwwww"<<endl;
					  	break;

			case J:		//bool isneg=false;
					if(Addr.to_string()[6]=='1')
					{
						string s=TwosComplement(Addr.to_string().substr(6,26));
						Addr= bitset<32>(makesize(s,32));
						isneg=true;
					}
					if(isneg)
					{
						nextPC = bitset<32> (currPC.to_ulong() - (Addr.to_ulong()/4) - 1);
					}else{
						nextPC = bitset<32> (currPC.to_ulong() + (Addr.to_ulong()/4) - 1);}
						break;

			case JAL:	//bool isneg=false;
					if(Addr.to_string()[6]=='1')
					{
						string s=TwosComplement(Addr.to_string().substr(6,26));
						Addr= bitset<32>(makesize(s,32));
						isneg=true;
					}
					if(isneg)
					{
						nextPC = bitset<32> (currPC.to_ulong() - (Addr.to_ulong()/4) - 1);
					}else{
						nextPC = bitset<32> (currPC.to_ulong() + (Addr.to_ulong()/4) - 1);}
					ALUResult=bitset<32> (currPC.to_ulong()+1);
						break;

			case JR:	nextPC=myRF.getra();
						break;

			case BEQ:	ALUResult = 0;
						if(regVals[0] == regVals[1]){
							//bool isneg=false;
							if(ImmVal.to_string()[16]=='1')
							{
								string s=TwosComplement(ImmVal.to_string().substr(16,16));
								ImmVal= bitset<32>(makesize(s,32));
								isneg=true;
							}
							if (isneg)
							{
								nextPC = bitset<32> (currPC.to_ulong() - (ImmVal.to_ulong()/4)-1);
							}else{
							nextPC = bitset<32> (currPC.to_ulong() + (ImmVal.to_ulong()/4) - 1);}
						}
						break;

			case BNE:	ALUResult = 0;//cout<<"eeeeeeeeeeeeeeeeeeeeeeeffffffffffffffffffffffffffff"<<endl;
						if(regVals[0] != regVals[1]){
							//bool isneg=false;
							if(ImmVal.to_string()[16]=='1')
							{
								string s=TwosComplement(ImmVal.to_string().substr(16,16));
								ImmVal= bitset<32>(makesize(s,32));
								isneg=true;
							}
							if (isneg)
							{
								nextPC = bitset<32> (currPC.to_ulong() - (ImmVal.to_ulong()/4)-1);
							}else{
							nextPC = bitset<32> (currPC.to_ulong() + (ImmVal.to_ulong()/4) - 1);}
							ALUResult = 1;//cout<<"eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"<<nextPC<<endl;
						}
						break;

			case BLEZ:	ALUResult = 0;
						if(regVals[0].to_ulong() <= 0){
							//bool isneg=false;
							if(ImmVal.to_string()[16]=='1')
							{
								string s=TwosComplement(ImmVal.to_string().substr(16,16));
								ImmVal= bitset<32>(makesize(s,32));
								isneg=true;
							}
							if (isneg)
							{
								nextPC = bitset<32> (currPC.to_ulong() - (ImmVal.to_ulong()/4)-1);
							}else{
							nextPC = bitset<32> (currPC.to_ulong() + (ImmVal.to_ulong()/4) - 1);}
						}
						break;

			case BGTZ:	ALUResult = 0;
						if(regVals[0].to_ulong() >0){
							//bool isneg=false;
							if(ImmVal.to_string()[16]=='1')
							{
								string s=TwosComplement(ImmVal.to_string().substr(16,16));
								ImmVal= bitset<32>(makesize(s,32));
								isneg=true;
							}
							if (isneg)
							{
								nextPC = bitset<32> (currPC.to_ulong() - (ImmVal.to_ulong()/4)-1);
							}else{
							nextPC = bitset<32> (currPC.to_ulong() + (ImmVal.to_ulong()/4) - 1);}
						}
						break;
		
			case HLT: break; // do nothing, loop will terminate

			default: break; // silently skip instruction
		}
	}


	/* Stage 4: Memory Operations and branching */
	void memoryOpsAndBranch(bitset<32> ALUResult,bitset<32> loc,bitset<32> nextPC,int opcode, bool &flushFlag,bitset<32> &newALUResult,bitset<32> &PCaddrAfterFlush){

		flushFlag = false; 

		switch(opcode){
			case LW:	newALUResult = myDataMem.MemoryAccess(loc,NULL,1,0);
						break;

			case SW:	myDataMem.MemoryAccess(loc,ALUResult,0,1);
						break;

			case J:		PCaddrAfterFlush = nextPC;
						// flush pipeline
						flushFlag = true;
						break;

			case JAL:	PCaddrAfterFlush = nextPC;
					newALUResult=ALUResult;myRF.Registers[31]=newALUResult;
						// flush pipeline
						flushFlag = true;
						break;

			case JR:	PCaddrAfterFlush = nextPC;
						// flush pipeline
						flushFlag = true;
						break;

			case BEQ:	if(ALUResult.to_ulong()){
							PCaddrAfterFlush = nextPC;
							// flush pipeline
							flushFlag = true;
						}
						break;

			case BNE:	if(ALUResult.to_ulong()){
							PCaddrAfterFlush = nextPC;
							// flush pipeline
							flushFlag = true;
						}
						break;

			case BLEZ:	if(ALUResult.to_ulong()){
							PCaddrAfterFlush = nextPC;
							// flush pipeline
							flushFlag = true;
						}
						break;

			case BGTZ:	if(ALUResult.to_ulong()){
							PCaddrAfterFlush = nextPC;
							// flush pipeline
							flushFlag = true;
						}
						break;

			default:	newALUResult = ALUResult;
						break;
		}
	}

	/* Stage 5: Write vals to register file */
	void writeBack(bitset<32> ALUResult, int tgtReg, int opcode){
		if(	
			opcode == ADD  || 
			opcode == SLL || 
			opcode == SUB  || 
			opcode == SRL ||
			opcode == LW  ||
			opcode == JAL
		  ){	
			myRF.ReadWrite(NULL,NULL,bitset<5>(tgtReg),ALUResult,1);	
		}
	}

public:

	/*
		Public Interface for the class
	*/

	/* Initialize data members */
	Processor(){
		programCounter=bitset<32>(0);
		myRF.openwrite();
	}

	/* Simulation Begin */
	void start(){
		
		// Flags to suppress pipeline stage work in a cycle
		#define WB_STAGE  4
		#define MEM_STAGE 3
		#define EXE_STAGE 2
		#define DEC_STAGE 1
		#define FI_STAGE  0
		int locks[5] = { 0, 1, 2, 3, 4 };
		//cout<<"PC "<<programCounter<<endl;
		/* Data Forwarding */
		bitset<32> lastComputedVals[3];
		bitset<32> lastinstructions[5];
		bitset<32> oldinstruction;
		string lastComputedRegs[3];
		for(int idx=0; idx<3; idx++){	lastComputedRegs[idx] = "100000";}
		for(int idx=0; idx<5; idx++){	lastinstructions[idx] = bitset<32>(0);}

		/* Interface Variable Declarations */
		
		bitset<32> oldPC;
		int opcode;
		string regIds[3];
		bitset<32> regVals[3];
		bitset<32> ImmVal;
		bitset<32> Addr;

		bitset<32> ALUResult;
		bitset<32> loc;
		bitset<32> nextPC; int nextPCflag = 0;
		int oldOpcode;

		bitset<32> newALUResult;
		int tgtReg;
		int oldTgtReg;
		int olderOpcode;
		int instcount=0;
		int count=0;
		bool flushFlag;
		bitset<32> PCaddrAfterFlush;
		
		// Simulate in reverse order of stages to avoid temporary variables (buffer registers)
		do{//cout<<" in loop"<<endl;
			//cout<<regIds[1]<<"locks"<<endl;
		   	cout<<"PC"<<programCounter<<endl;count++;
			lastinstructions[0]=lastinstructions[1];
			lastinstructions[1]=lastinstructions[2];
			lastinstructions[2]=lastinstructions[3];
			lastinstructions[3]=lastinstructions[4];
			/*
				Stage 5 - Write Back
			*/

			if(!locks[WB_STAGE]){
				// write back
				instcount++;
				writeBack(newALUResult, oldTgtReg, olderOpcode);
				cout<<"writing back"<<endl;
				cout<<lastinstructions[0]<<" instruction in WB"<<endl;
				//for(int i=0;i<32;i++) cout<<myRF.Registers[i]<<endl;
				myRF.OutputRF(); 
				//break;
				// Check termination
				if(olderOpcode == HLT)
					break;
			}
			else
				locks[WB_STAGE]--;

			/*
				Stage 4 - Memory Operations & PC updation & flushing
			*/

			olderOpcode = oldOpcode;
			oldTgtReg = tgtReg;

			if(!locks[MEM_STAGE]){
				/*
					Notice no data forwarding is reqd for data stored in memory cause memory read 
					and writes are not separated by any pipeline stages.
				*/
				cout<<"mem stage"<<endl;
				// Mem Ops & branch
				memoryOpsAndBranch(ALUResult, loc, nextPC, oldOpcode, flushFlag, newALUResult, PCaddrAfterFlush);
				cout<<lastinstructions[1]<<" instructions in MEM"<<endl;
				/* Some data forwarding*/
				if(oldOpcode == LW){
					lastComputedRegs[2] = (bitset<5>(tgtReg)).to_string();
					lastComputedVals[2] = newALUResult;
				}
			}
			else
				locks[MEM_STAGE]--;

			/*
				Stage 3 - Execute 
			*/
			
			oldOpcode = opcode;
			if (opcode==LW || opcode==SW){
			if (randomwithProb(.5) == 1){
			locks={0,1,2,3,4,5};}}
			
			if (opcode==LW){
			tgtReg = binaryToDecimal(regIds[1]);}
			else if (opcode ==JAL){tgtReg=31;}
			else{tgtReg=binaryToDecimal(regIds[2]);}

			// Data Forwarding here
			for(int idx=0; idx<3; idx++){
			//cout<<lastComputedRegs[0]<<" "<<lastComputedRegs[1]<<" "<<lastComputedRegs[2]<<" "<<regIds[idx]<<endl;
				if(regIds[idx] == lastComputedRegs[2])
					{regVals[idx] = lastComputedVals[2];}
				else if(regIds[idx] == lastComputedRegs[1])
					{regVals[idx] = lastComputedVals[1];}
				else if(regIds[idx] == lastComputedRegs[0])
					{regVals[idx] = lastComputedVals[0];}
			}

			bool isExececuted = false;
			if(!locks[EXE_STAGE]){
				// Execute
				cout<<"execute"<<endl;
				cout<<lastinstructions[2]<<" instruction in EXE"<<endl;
				execute(oldinstruction,opcode, regVals, ImmVal, Addr, oldPC, ALUResult, loc, nextPC);
								
				isExececuted = true;
			}
			else
				locks[EXE_STAGE]--;

			// Cycle the stored vals
			lastComputedRegs[0] = lastComputedRegs[1];
			lastComputedRegs[1] = lastComputedRegs[2];
			lastComputedVals[0] = lastComputedVals[1];
			lastComputedVals[1] = lastComputedVals[2];


			//for(int idx=0; idx<3; idx++){ cout<<lastComputedRegs[idx]<<endl;}
			// Store latest computed value
			if(	isExececuted && !flushFlag && 
				(
					opcode == ADD || 
					opcode == SLL || 
					opcode == SUB || 
					opcode == SRL 
				) 
			  ){
				lastComputedVals[2] = ALUResult;
				lastComputedRegs[2] = regIds[2];
				//cout<<"update here"<<regIds[1]<<endl;	
			}
			else{
				lastComputedRegs[2] = "100000";	//cout<<"32 it is"<<endl;					
			}

			/*
				Stage 2 - Decode and Fetch Operands 
			*/

			oldPC = programCounter;

			if(!locks[DEC_STAGE]){
				cout<<"decode"<<endl;
				decodeAndOperandFetch(instruction, opcode, regIds, regVals, ImmVal, Addr);
				oldinstruction=instruction;
				lastinstructions[3]=oldinstruction;
				cout<<lastinstructions[3]<<" instruction in DEC"<<endl;
				//for(int i=0;i<3;i++){cout<<regIds[i]<<endl;}
			}
			else
				locks[DEC_STAGE]--;

			/*
				Stage 1 - Fetch & Increment PC
			*/
			
			if(!locks[FI_STAGE]){
				cout<<"IF"<<endl;
				instrFetch();
				lastinstructions[4]=instruction;
				cout<<lastinstructions[4]<<" instruction in IF"<<endl;
			}
			else
				locks[FI_STAGE]--;

			/*
				Flush pipeline if triggered
			*/
			if(flushFlag){
				locks[0] = 0; locks[1] = 1; locks[2] = 2; locks[3] = 3; locks[4] = 4;
				flushFlag = false;
				programCounter = PCaddrAfterFlush;
			}
	        
		} while(true);cout<<"Total number of clock cycles taken is "<< count-1<<endl;
				cout<<"Total number of instructions are "<< instcount+1<<endl;
				cout<<"Instruction per cycle is "<< (instcount+1)/((double)(count-1))<<endl;
 //cout<<myRF.Registers[31]<<endl;
myRF.closeWrite();
	}
	
	/* Save Memory Dump to outfile */
	void generateDump()
	{
		myDataMem.OutputDataMem();
	}

} SimulationProcessor;


int main(int argc, char *argv[]){
	
	// Simulate Processor on binary
	SimulationProcessor.start();
	
	// Dump memory to file
	SimulationProcessor.generateDump();	

	return 0;
}
