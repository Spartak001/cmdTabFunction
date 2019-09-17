#include "pch.h"
#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<iterator>
#include<conio.h>
#include<thread>
#include<thread>
#include<chrono>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

bool testforstart(const char*test, string &imput, string&otherimp,int &x);


string* dotab(vector<string>&com,string &imp)
{
	string gg;
	int ptab = imp.length()-1;
	int ptab2 = ptab;
	string ch2;
	int mtmp = 0;
	int max = 0;
	int st = 0;
	int end = 0;
	int index = 0;
	int k = 0;
	bool f = true;
	bool f2 = true;
	bool f3 = true;
	bool br = false;
	int h = 0;
	int t = 0;
	int zertest = 0;
	int k4 = 0;
		while (imp[ptab] != ' ')
		{
			if (ptab != 0)
				--ptab;
			else
			{
				ptab = 0;
				zertest = 1;
				break;
			}
		}
		if (zertest == 0)
		{
			while (ptab + 1 <= ptab2)
			{
				ch2 += imp[ptab + 1];
				ptab++;
			}
		}
		else
		{
		for (int i = 0; i < imp.size(); i++)////
		{
			ch2 += imp[i];
		}
		}
		for (int j = 0; j < com.size(); j++)
		{
			f3 = true;
			f2 = true;
			f = true;
			mtmp = 0;
			int g = 0;
			for (k = 0; k < com[j].size(); k++)
			{

				if (com[j][k] == ch2[g] && f3)
				{
					if (f)
					{
						h = k;
						f = false;
					}
					mtmp++;
					g++;
				}
				else if (f == false && f2&&g==ch2.size())
				{
					t = k;
					f2 = false;
					f3 = false;
					//break;
				}
				else if(com[j][k]!=ch2[g])
				{
					while (com[j][k] != ' ')
					{
						k++;
						//if (k == com[j].size())
						//{
							//break;
						//}
					}
					g = 0;
					f3 = true;
					f = true;

				}

			}
			if (mtmp > max && testforstart(com[j].c_str(),imp,gg,k4=0))
			{
				max = mtmp;
				index = j;
				end = t;
				st = h;
			}

		}
		for (int i = end; i < com[index].size(); i++)
		{
			if (com[index][i] != ' ')
			{
				imp += com[index][i];
			}
			else
			{
				break;
			}

		}
		imp += " ";
		return &imp;
}

bool testw(vector<string>&com, string &imp)
{
	int test = 0;
	for (int i = 0; i < com.size(); i++)
	{
		for (int j = 0; j < com[i].size(); j++)
		{
			if (com[i][j] == imp[j])
			{
				test = 1;
			}
			break;
		}
	}
	/*if (find(com.begin(), com.end(), imp) != com.end())
	{
		test = 1;
	}*/
	if (test == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool testforstart2(string&imput, const char* text,int x)
{
	int k = 0;
	int g = 0;
	while (k!=imput.size())
	{
		if (text[x] != imput[k])
		{
			break;
		}
		x++;
		k++;
		g++;
	}
	if (g == imput.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool testforstart(const char*test, string &imput,string&otherimp,int &x)
{
	int k = 0;
	int j = 0;
	while (test[x] != '\0')
	{
		if (testforstart2(imput,test,x))
		{
			j = x;
			while (test[j] != ' ')
			{
				otherimp += test[j];
				j++;
			}
			return true;
		}
		else
		{
			while (test[x] != ' ')
			{
				x++;
			}
			x++;
		}
	}
	return false;
}


bool testsubstr(vector<string> &vec, string &imput)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (strstr(vec[i].c_str(), imput.c_str()) != NULL)
		{
			return true;
		}
	}
	return false;
}



bool tester(vector<string>&vec, string&impute)
{
	int k = 0;
	vector<string>nvec;
	string other;
	string imput;
	string imputr = impute;
	int z = 0;
	for (int i = imputr.size(); i > 0; i--)
	{
		if (i==1||imputr[i] == ' ')
		{
			if (i != 1)
			{
				z = i + 1;
				while (imputr[z] != '\0')
				{
					imput += imputr[z];
					z++;
				}
				break;
			}
			else
			{
				z = 0;
				while (imputr[z] != '\0')
				{
					imput+=imputr[z];
					z++;
				}
				break;
			}
		}
	}
	
	
	
	for (int i = 0; i < vec.size(); i++)
	{
		for (int kz = 0; kz < vec[i].size(); kz++)
		{
			other = "";
			if ((strstr(vec[i].c_str(), imput.c_str()) != NULL) && (testforstart(vec[i].c_str(), imput, other,kz)))
			{
				if (find(nvec.begin(), nvec.end(), other) == nvec.end())
				{
					k++;
					nvec.push_back(other);
				}
			}
			while (vec[i][kz] != ' ')
			{
				if (kz == vec[i].size())
				{
					break;
				}
				kz++;
			}
		}
		
	}
	if (k == 1)
	{
		return true;
	}
	return false;
}

string* imputting(string &imput,vector<string> &vec, vector<string> &arrowstr)
{
	string other = "";
	int chi = 0;
	int zz = 0;
	int size = arrowstr.size();
	int size2 = 0;
	int recsize = 0;
	int f = 0;
	int keyright = 0;
	bool keyforleft = false;
	int leftsize = 0;
	int tst = 0;
	bool fir = false;
	int first = 0;
	bool beck = false;
	int kk = 0;
	bool keyrighte = false;
	int keyforbeck = 0;
	while (true)
	{
		char ch = _getch();
		if (ch == '\b')
		{
			if (!keyforleft)
			{
				zz = 0;
				imput = imput.substr(0, imput.size() - 1);
				cout << "\010 \010" << flush;
			}
			else
			{
				string other;
				for (int i = 0; i <recsize ; i++)
				{
					if (i == size2)
					{
						continue;
					}
					other += imput[i];
				}
				system("CLS");
				imput = other;
				for (int i = size2; i < recsize-1; i++)
				{
					imput += '\b';
				}
				cout << imput;
				zz = 0;
				beck = true;
				recsize--;
				keyforbeck++;
			}

			/*
			else
			{
				string other2;
				int tmpsize = size2;
				int g = 0;
				for (int i = 0; i < imput.size()-leftsize; i++)
				{
					if (i != size2+1)
					{
						other2 += imput[i];
					}
					else
					{
						continue;
					}
					keyright = recsize;
				}
				system("CLS");
				zz = 0;
				imput = other2;
				size2 = imput.size()-1;
				leftsize = 0;
				cout << imput;
				keyforleft = false;
				
			}
			*/
			if (imput.size() == 0)
			{
				first = 0;
			}
			//keyforleft = false;
			chi = 0;
			
		}
		else if (ch == '\t')
		{
			if (first >=2)
			{
				if (testsubstr(vec, imput))
				{

					if (tester(vec, imput))
					{
						if (chi == 0)
						{
							dotab(vec, imput);
							system("CLS");
							cout << imput;
							chi = 1;
						}
					}
				}
			}
			else
			{
				if (first == 0)
				{
					system("CLS");
					imput = "";
					imput += "set ";
					cout << imput;
					first++;
					continue;
				}
				else
				{
					system("CLS");
					imput = "";
					imput += "get ";
					cout << imput;
					first = 0;
					continue;
				}
			}
			
		}
		else if (ch == '\r')
		{
			for (int i = imput.size(); i > 0; i--)
			{
				if (imput[i] == '\b')
				{
					imput.erase(i);
				}
			}
			
			arrowstr.push_back(imput);
			//imput += ' ';
			return &imput;
		}
		else if (ch == KEY_UP)
		{
			if (size == -1||size==0)
			{
				continue;
			}
			system("CLS");
			cout << arrowstr[size - 1];
			imput = arrowstr[size - 1];
			size--;
			fir = true;
		}
		else if (ch == KEY_DOWN)
		{
			if (fir)
			{
				if (size == arrowstr.size() - 1)
				{
					continue;
				}
				size++;
				system("CLS");
				cout << arrowstr[size];
				imput = arrowstr[size];
			}
			else
				continue;
		}
		
		else if (ch == KEY_LEFT)
		{
			//leftsize++;
			
			if (f == 0)
			{
				recsize = imput.size();
				size2 = imput.size();
				keyright = imput.size();

			}
			if (size2 == 0)
			{
				continue;
			}
			system("CLS");
			imput += '\b';
			cout << imput;
			zz++;
			if (size2 >=0)
			{
				size2--;
			}
			f++;
			keyforleft = true;
			keyright--;
			keyforbeck = 0;
			
			
		}
		
		else if(ch!='à')
		{

			first+= 3;
			if (ch == KEY_RIGHT)
			{
				/*keyright = true;
				if (size2 == recsize-1)
				{
					continue;
				}
				system("CLS");
				if (size2 != recsize -2)
				{
					imput += imput[size2 + 1];

					
					
				}
				else
				{
					imput += imput[size2+1];
					
				}
				cout << imput;
				size2++;*/
				/*if (keyright <= recsize)
				{
					system("CLS");
					imput = imput.substr(0, imput.size() - 1);
					cout << imput;
					keyright++;
					//size2++;
				}
				else*/

				if (keyright < recsize)
				{
					system("CLS");
					imput = imput.substr(0, imput.size() - 1);
					cout << imput;
					size2++;
					keyright++;
				}
				if (keyright == recsize)
				{
					zz = 0;
					beck = false;
					keyforleft = false;
				}

				
			}
			else if (zz == 0&&!beck)
			{
				system("CLS");
				imput.push_back(ch);
				cout << imput << flush;
				other = imput;
				other += ch;
				chi = 0;
				f = 0;
			}
			else
			{
				if (keyforbeck == 0)
				{
					string other;
					for (int i = 0; i < recsize + 1; i++)
					{
						if (i == size2 + 1)
						{
							other += ch;

						}
						other += imput[i];

					}
					beck = false;
					system("CLS");
					imput = other;
					for (int i = size2; i < recsize; i++)
					{
						imput += '\b';

					}
					cout << imput;
					recsize++;
				}
				else
				{
					string other;
					for (int i = 0; i < recsize + 1; i++)
					{
						if (i == size2)
						{
							other += ch;

						}
						other += imput[i];

					}
					beck = false;
					system("CLS");
					imput = other;
					for (int i = size2; i < recsize; i++)
					{
						imput += '\b';

					}
					cout << imput;
					recsize++;
					keyforbeck = 0;
					//size2++;
					
				}
			}
			/*else
			{

				system("CLS");
				imput[size2] = ch;
				cout << imput;
			}*/
			/*
			else
			{
				system("CLS");
				if (tst = 0)
				{
					imput[size2 - 2] = ch;
					imput += ch;
					//imput += ch; 
					//size2++;
				}
				else
					
				imput[size2+1] = ch;
			    //imput += "";
				imput += ch; 
				//size2++;

				cout << imput;
				other = imput;
				other += ch;
				chi = 0;
				zz == 0;
				//size2++;
				tst++;
				f = 0;
				
			}
			*/
			
		}
	}
	f = 0;
}

void testimput()
{
	vector<string> comands;
	comands.push_back("set int laser on ");
	comands.push_back("set int laser off ");
	comands.push_back("set ext laser on ");
	comands.push_back("set ext laser on ");
	comands.push_back("set pump on ");
	comands.push_back("set pump off ");
	comands.push_back("set sampling rate 10 ");
	comands.push_back("set location ");
	comands.push_back("set scan direction ");
	comands.push_back("get int laser status ");
	comands.push_back("get ext laser status ");
	comands.push_back("get pump status ");
	comands.push_back("get vacum pressure ");
	comands.push_back("get power status ");
	comands.push_back("get sampling rate ");
	comands.push_back("get station id ");
	comands.push_back("get network params ");
	comands.push_back("get camera temperature ");
	comands.push_back("get camera humidity ");
	comands.push_back("get camera pressure ");
	comands.push_back("set step motor<1> move to<4000> ");
	comands.push_back("set step motor<1> reset ");
	comands.push_back("get coefficients ");
	comands.push_back("register pli station ");
	comands.push_back("upgrade firmware ");
	comands.push_back("upgrade license ");
	comands.push_back("scan interferometer ");
	comands.push_back("scan acces ");
	comands.push_back("calibrate ");

	//string s1 = "set int laser on ";
	//string s3 = "set step lastr off ";
	//vector<string> comands;
	//comands.push_back(s1);
	////comands.push_back(s2);
	//comands.push_back(s3);
	////comands.push_back(s4);
	string imput;
	vector<string> arrowstr;
	int f = 0;
	int g1 = 0;
	int g = 0;
	string truch;
	vector<string> wrongwords;
	string wrongword;
	bool bo = true;
	bool bo2 = false;
	bool first = true;
	bool second = false;
	bool third = false;
	bool four = true;
	string truch2;
	while (1)
	{
		
			int f = 0;
			int g1 = 0;
			int g = 0;
			string truch;
			bool bo = true;
			bool bo2 = false;
			bool first = true;
			bool second = false;
			bool third = false;
			bool four = true;
			string truch2;
			system("CLS");
			imput = "";
			imputting(imput, comands, arrowstr);

			if (find(comands.begin(), comands.end(), imput) != comands.end())
			{
				cout << endl;
				cout << "comand is done" << endl;
				this_thread::sleep_for(chrono::milliseconds(1000));
				imput = "";
			}
			else if (testw(comands, imput))
			{
				cout << endl;
				cout << "wrong command" << endl;
				this_thread::sleep_for(chrono::milliseconds(1000));

			}
			else if (imput.size() < 8)
			{
				cout << endl;
				cout << "comand is not complte";
			}
			else
			{
				int max2 = 0;
				int index2 = 0;
				for (int i = 0; i < comands.size(); i++)
				{
					g1 = 0;
					truch2 = "";
					for (int j = 0; j < comands[i].size(); j++)
					{

						if (comands[i][j] == imput[j])
						{
							truch2 += imput[j];
							g1++;


						}
						else if (g1 > max2)
						{
							g = g1;
							max2 = g1;
							index2 = i;
							truch = truch2;
							second = true;
						}
						else
						{
							second = true;
						}
						if (i == comands.size() - 1 && second)
						{
							cout << endl;
							if (bo)
							{
								for (int t = 0; t < g; t++)
								{
									cout << " ";
								}
								bo = false;
								cout << "^" << endl;
							}
							for (int i = 0; i < comands.size(); i++)
							{
								bool th = false;
								f = 0;
								four = true;
 								for (int j = 0; j <= g; j++)
								{
									if (comands[i].size() <= g)
									{
										break;
									}
									if (comands[i][j] == truch[j] && four)
									{
										f++;
										th = false;

									}
									if (f == g)
									{
										int g2 = g;
										int g3 = g;
										four = false;
										//cout << "you may have wanted to say {" << comands[i] << "}" << endl;
										if (comands[i][g] != ' '&&comands[i][g-1]!=' ')
										{
											while (comands[i][g2] != ' ')
											{
												if (g2 == 0)
												{
													break;
												}
												g2--;
											}
										}
										else if(comands[i][g] == ' ')
										{
											g2--;
											while (comands[i][g2] != ' ')
											{
												if (g2 == 0)
												{
													break;
												}
												g2--;
											}
										}
										
										while (comands[i][g3] != ' ')
										{
											if (g3 == comands[i].size())
											{
												break;
											}
											else
											{
												g3++;
											}
										}
										for (int i1 = g2; i1 < g3; i1++)
										{
											wrongword += comands[i][i1];
										}

										if (find(wrongwords.begin(), wrongwords.end(), wrongword) == wrongwords.end() || first)
										{
											if (wrongword[0] == comands[i][g2])
											{

												cout << "you may wanted to say: ";
												for (int i1 = g2; i1 < g3; i1++)
												{
													cout << comands[i][i1];

												}
												wrongwords.push_back(wrongword);
												wrongword = "";
												cout << endl;
												f = 0;
												first = false;
											}
											else
											{
												cout << "wrong";
												break;
											}

										}
										wrongword = "";

									}
									if (th)
									{
										f = 0;
									}
									th = true;
									bo2 = true;
								}
							}
							if (bo2)
							{
								break;
							}

						}
						else if (second)
						{
							second = false;
							break;
						}
					}
					if (bo2)
					{
						break;
					}
				}
				this_thread::sleep_for(chrono::milliseconds(5000));

			}
		
		
	}
}




int main()
{
	/*string com1 = "set int laser on";
	string com2 = "get power off";
	vector<string> vec;
	vec.push_back(com1);
	vec.push_back(com2);
	string imput;
	

	while (true)
	{
		char ch = _getch();
		if (ch == '\b')
		{
			imput = imput.substr(0, imput.size() - 1);
			cout << "\010 \010" << flush;
		}
		else if (ch == '\t')
		{
			foo(vec, imput);
			system("CLS");
			cout << imput;
		}
		else
		{
			imput.push_back(ch);
			system("CLS");
			cout << imput << flush;
		}
	}
	*/
	while (true)
	{
		testimput();
	}
	return 0;
}