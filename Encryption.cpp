#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string.h>
#include <math.h>
using namespace std;

#define KEY_ROW 27
#define KEY_COLUMN 19

//#define TESTCASE2

//#define DEBUG

//#define AUTO

const char no_output[] = {"No testcase is matched with plaintext."};

const char test_case2[5][501] = {"masterwork swept squanders grounders idolatries swapper pave croupier dramatists magnified hypnoses delivery tassels marquise entailments circuits crampon nationalism nictitation anticapitalists dancingly soothly patriarchs goodie whickers baggy omnipotent sadist ameba processions beggary rename nonassertively macerators lectureship shipwrights sadden backups rhymer offstage schistose ebbs restorer graecizes subjoining leathering smocks leukocyte waled temperer embroglios bolivar repines teletyr", "wharves locoisms tearjerkers remiss chops duties prolonged inequities minnows itemized thematically scorecard deliverers jokingly semiosis claspers brazenness grateful collarbones stamping bittersweets habilitation endorsers decrepitly tambourine shadowboxes adopting ingenuous disquisitions quietist innovates mingles nationals disparaging exults realtor cockade rubberizing tubercled unremitting sloppiest algin knuckleball disengage domes doltishly encyclics spectroscopically debauched circumsola", "ozonise creosotes disruption neighborly lunier shagging balancing adriatic dick guesstimate storminess jest soberer spun toolbox crochet firebreak parliamentary undismayed lintiest homoeroticism silverfishes cornstalk digest subtler ruck cairns wombat working synapsed diamonding association opalescence crenation bumblebees undetected sandwiching unpeoples polishes schoolwork familarity flaying slued soothers splenification dare hydrology gourami alligators varsity statuettes gainly feeding filme", "autarky sartor terbium synapse herr eugenicists isthmian reembarks spinet dictaphone ecology carinae coeducational carburizing undulated twopenny subscriptions wrigglier scaliness enthrallingly carvers russified rejoice anaconda switzerland sallows devotedly pledgees incongruous miriest nonextraditable extrospection clipping souffle mimicry interrupts reputably reteaches quicksets bankroll hallucinated unzealous invocation winless yacking shinbone tonal vasoconstrictive manioc gourami purling ey", "championships iatrogenic maniacally antonym schoolboy shyly leafhoppers inturned sunbathing overrefined obliterations discus maintain cranked uniters twangled impairer wreakers forewings silesia occupance headroom foresting ornithologists shims lackaday benumbedness gloomy sententious fussing flagrant consonance profligately scutcheons honda swooned headworks zeins intermezzo adaptions elbow ocotillos denim japers thalamic corinthians restraightening kowtowed embarrasses latissimi impoverished s"};

const char test_case[5][501] = {"masterwork swept squanders grounders idolatries swapper pave croupier dramatists magnified hypnoses delivery tassels marquise entailments circuits crampon nationalism nictitation anticapitalists dancingly soothly patriarchs goodie whickers baggy omnipotent sadist ameba processions beggary rename nonassertively macerators lectureship shipwrights sadden backups rhymer offstage schistose ebbs restorer graecizes subjoining leathering smocks leukocyte waled temperer embroglios bolivar repines teletyp", "wharves locoisms tearjerkers remiss chops duties prolonged inequities minnows itemized thematically scorecard deliverers jokingly semiosis claspers brazenness grateful collarbones stamping bittersweets habilitation endorsers decrepitly tambourine shadowboxes adopting ingenuous disquisitions quietist innovates mingles nationals disparaging exults realtor cockade rubberizing tubercled unremitting sloppiest algin knuckleball disengage domes doltishly encyclics spectroscopically debauched circumsola", "ozonise creosotes disruption neighborly lunier shagging balancing adriatic dick guesstimate storminess jest soberer spun toolbox crochet firebreak parliamentary undismayed lintiest homoeroticism silverfishes cornstalk digest subtler ruck cairns wombat working synapsed diamonding association opalescence crenation bumblebees undetected sandwiching unpeoples polishes schoolwork familarity flaying slued soothers splenification dare hydrology gourami alligators varsity statuettes gainly feeding filme", "autarky sartor terbium synapse herr eugenicists isthmian reembarks spinet dictaphone ecology carinae coeducational carburizing undulated twopenny subscriptions wrigglier scaliness enthrallingly carvers russified rejoice anaconda switzerland sallows devotedly pledgees incongruous miriest nonextraditable extrospection clipping souffle mimicry interrupts reputably reteaches quicksets bankroll hallucinated unzealous invocation winless yacking shinbone tonal vasoconstrictive manioc gourami purling ey", "championships iatrogenic maniacally antonym schoolboy shyly leafhoppers inturned sunbathing overrefined obliterations discus maintain cranked uniters twangled impairer wreakers forewings silesia occupance headroom foresting ornithologists shims lackaday benumbedness gloomy sententious fussing flagrant consonance profligately scutcheons honda swooned headworks zeins intermezzo adaptions elbow ocotillos denim japers thalamic corinthians restraightening kowtowed embarrasses latissimi impoverished s"};

#ifdef AUTO
int random_array[106] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105};
#endif
float actual_weight[27]={11.11,7.22389,1.8562,3.83946,3.48084,11.0159,1.29839,2.73235,2.10624,8.31578,0.178395,0.826727,5.10324,2.605,6.58571,5.82362,2.68029,0.173727,7.00349,8.45673,6.30645,3.16951,0.986654,0.813637,0.275813,1.60789,0.416154};
int alphabet_weight[27] = {19,7,1,2,4,10,2,2,5,6,1,1,3,2,6,6,2,1,5,5,7,2,1,2,1,2,1};
int alphabet_weight_orig[27] = {11,7,2,4,3,11,1,3,2,8,0,1,5,3,7,6,3,0,7,8,6,3,1,1,0,2,0};
string cipher(const char * pt, int length);
void decipher(int *ct, int length, char *pt);
string decipher2(int *ct, int length, int ***key_decipher);
string decipher3(int *ct, int length, int **key_d);
int filter(int ctx, char test_onex, int **key);

void print_key(int **key) {
#ifdef DEBUG
    int count = 0, count2 = 96;
    for(int j=0;j<513;j++)
    {
	cout.width(3);
        cout<< key[j/KEY_COLUMN][j%KEY_COLUMN]<<" ";
	if(key[j/KEY_COLUMN][j%KEY_COLUMN] && (key[j/KEY_COLUMN][j%KEY_COLUMN] < 106) )
	    count++;
	if(j%KEY_COLUMN == KEY_COLUMN - 1) {
	    cout << " = " << (char)(count2++) << " " << count << "\n";
	    count = 0;
	}
    }
    cout << "\n";
#endif
}

void print_key2(int **key) {
#ifdef DEBUG
    int count = 0, count2 = 96, k;

    for(int j=0;j<27;j++)
    {
	cout.width(4);
	cout << (char)(96+j) << " ";
    }
    cout << endl;
    for(int j=0;j<27;j++)
    {
    	for(int k=0;k<27;k++)
    	{
		cout.width(4);
        	cout<< key[j][k]<<" ";
		count += key[j][k];
	}
	cout << "=" << count << "\n";
	count = 0;
    }
    cout << "\n";
#endif
}

int filter(int ctx, char test_onex, int **key1) {
    char alphabet;
    int alphabet_row, i,j,k;
	alphabet_row = 50;
	if(test_onex<97)
	    alphabet=0;
	else
	    alphabet = test_onex - 96;
#ifdef DEBUG
	cout << test_onex << " ";
#endif
	for(j=0;j<KEY_ROW;j++) {
	    for(k=0;k<alphabet_weight[j];k++) {
		if(key1[j][k] == ctx){
		    alphabet_row = j;
		    goto break_loop;
		}
	    }
	}
	for(k=0;k<KEY_COLUMN;k++) {
	    if(key1[alphabet][k]==150) {
		key1[alphabet][k] = ctx;
		if(k+1>alphabet_weight[alphabet]) {
		    //cout <<"size of the "<< test_onex << " is " << alphabet_weight[alphabet] << " but it is now become " << k+1;
	            //cout <<"\n";
	            //print_key(key1);
	            //cout << "Plaintext is not 0\n";
		    return 0;
		}
		break;
	    }
	}
	break_loop:
	if(alphabet != alphabet_row && alphabet_row != 50) {
	    //cout << "\nsymbol " << ctx <<" is trying to assign to '"<<test_onex <<"'\n";
	    //print_key(key1);
	    //cout << "Plaintext is not 0\n";
	    return 0;
	}
	return 1;
}

string decipher2(int *ct, int length, int ***key_decipher) {
    int i;
    int correct_pt[5]={1,1,1,1,1},final_pt;
    i = 0;
    cout << "\nFor testcase1\n";
    do {
	if(correct_pt[0])
	    correct_pt[0]=filter(ct[i],test_case[0][i],key_decipher[0]);
	if(correct_pt[1])
	    correct_pt[1]=filter(ct[i],test_case[1][i],key_decipher[1]);
	if(correct_pt[2])
	    correct_pt[2]=filter(ct[i],test_case[2][i],key_decipher[2]);
	if(correct_pt[3])
	    correct_pt[3]=filter(ct[i],test_case[3][i],key_decipher[3]);
	if(correct_pt[4])
	    correct_pt[4]=filter(ct[i],test_case[4][i],key_decipher[4]);
	i++;
       //final_pt = correct_pt[0]+correct_pt[1]*2+correct_pt[2]*3+correct_pt[3]*4+correct_pt[4]*5;
    //}while(final_pt > 1);
    }while(i < length);
    final_pt = correct_pt[0] + correct_pt[1]*2+3*correct_pt[2]+4*correct_pt[3]+5*correct_pt[4];
#ifdef DEBUG
        cout << "\nlegnth = " << length << " final pt = " << final_pt << "\n";
	print_key(key_decipher[0]);
	print_key(key_decipher[1]);
	print_key(key_decipher[2]);
	print_key(key_decipher[3]);
	print_key(key_decipher[4]);
#endif
    if(final_pt) {
	return (string)test_case[final_pt - 1];
    } else {
	return (string) no_output;
    }
}

int main()
{
    int i,j,k,length,ct[500], count = 0;
    string plaintext_2, s, symbol;
    clock_t start,end;
    float seconds;

    int ***key_decipher;
    int **key_d;

    key_decipher = new int**[5];
    for(i=0;i<5;i++) {
	key_decipher[i] = new int *[KEY_ROW];
	for(j=0;j<KEY_ROW;j++) {
	    key_decipher[i][j] = new int[KEY_COLUMN];
	    for(k=0;k<KEY_COLUMN;k++) {
	        key_decipher[i][j][k] = 150;
	    }
	}
    }
    key_d = new int *[107];
        key_d[106] = new int[27];
        for(j=0;j<27;j++) {
	    key_d[106][j] = 0;
        }
    for(i=0;i<106;i++) {
        key_d[i] = new int[27];
        for(j=0;j<27;j++) {
            key_d[i][j] = 40;
	    key_d[106][j] += 40;
        }
    }
    
// Enter the plaintext
#ifdef AUTO    
    //srand (time(NULL));
    length = 500;
    s = cipher(test_case2[0], length);
#else
    cout << "Enter the  ciphertext : ";
//cout << "Maximum size of a string is " << s.max_size() << "\n";
    getline(cin, s);
#endif

// Find the length of the plaintext and convert from string to integer
    //length = s.length();
    for(i=0,j=0; i < s.length(); i++) {
	if(s[i]==',') {
	    ct[j++]=atoi(symbol.c_str());
	    symbol.clear();
	} else {
	symbol = symbol + s[i];
	}
    }
    ct[j++]=atoi(symbol.c_str());
    length = j;
   
#ifdef DEBUG
    cout <<"\n\n ct integer = " << i << " " << j << "\n";
    for(i=0;i<500;i++) {
	cout << ct[i] << " ";
    }
    cout << "\n\n";
#endif

// Start the clock
    start = clock();
    
// Decipher the plaintext
    plaintext_2 = decipher2(ct, length, key_decipher);
    end = clock();

// Display the result
    cout << "\n\nGuessed plaintext is : " << plaintext_2; 
    seconds = (float)(end - start)*1000 / CLOCKS_PER_SEC;
    cout << "\n\n Time = " << seconds << " ms";
    for(i=0;i<5;i++) {
	for(j=0;j<KEY_ROW;j++) {
	    delete[] key_decipher[i][j];
	}
	delete[] key_decipher[i];
    }
    delete[] key_decipher;
    cout << "\n\n";
    // if plaintext is not found by testcase1. Go to testcase2.
    if(plaintext_2 == no_output) {
	plaintext_2 = decipher3(ct, length, key_d);
	cout << "Guessed plaintext is : " << plaintext_2 << endl;	
    }
    for(i = 0; i < 106; ++i)
        delete[] key_d[i];
    delete[] key_d;
    return 0;
}

#ifdef AUTO
int random_generator()  // random generator function that excludes 76 to 94
{
    int rg;
    rg = rand() % 106;
    if(rg>=76 && rg<=94)
    {
        rg = random_generator();
    }
    return rg;
}

string cipher(const char *pt, int length) {
    int ct_int[500], i;
    string ct;
    unsigned char pt_c;
    int key_list;
    int** key = new int*[KEY_ROW];
    int counter = 0;
    for(i = 0; i < KEY_ROW; ++i)
        key[i] = new int[KEY_COLUMN];
     
    //If you want to randomize the entire key at each iteration, uncomment this line.
    
    int random_number;
    int temp1 = 0;
    
    //for(int j=0;j<19;j++)
    //{
    //    key[0][j] = 76+j;
    //}   // Giving key as (<space>,1)= 76,(<space>,2)= 77....(<space>,19)= 94
   

    for(int k=0;k<500;k++)
    {
        //if(temp1 == 75 ){temp1 = 95;}
        if(temp1 == 106 ){temp1 = 0;}
        random_number = random_generator();
       // cout<<"The Value Finally received is: "<< random_number<<'\n';
        int temp2 = random_array[random_number];
       // cout<<temp2<<" :random_array[random_number], ";
        random_array[random_number] = random_array[temp1];
       // cout<< random_array[random_number]<<" :random_array[temp1], ";
        random_array[temp1] = temp2;
       // cout<<random_array[temp1]<<" :temp2, ";
       // cout<<temp1<<" :temp1\n";
        temp1++;
        
    }
    
    for(int l=0;l<KEY_ROW;l++)
    {
        for(int m=0;m<alphabet_weight[l];m++)
        {
            //if(counter == 76 ){counter = 95;}
            key[l][m] = random_array[counter];
           // cout<<key[l][m]<<'\n';
            counter++;
           /* cout<<"The counter value is : "<<counter<<',';*/
        }
	//cout<<'\n';
    }    


#ifdef DEBUG
    cout<<"The key in Cipher : \n";
    print_key(key);
    cout << "pt = " << pt <<"\n";
#endif
    for(i=0;i<length;i++) {
	pt_c = pt[i];
	if(pt_c < 96)
	    key_list= 0;
	else
	    key_list = pt_c - 96;
      //cout << key_list << " ";
#ifdef TESTCASE2	
	ct_int[i] = key_list;//key[key_list][0];
#else
	ct_int[i] = key[key_list][rand()%alphabet_weight[key_list]];
#endif
	//cout << ct_int[i] << ",";
    }
    //cout << "\n";
    cout <<"\n\n string ct = ";
    for(i=0;i<500;i++) {
	ct = ct + to_string(ct_int[i]);
	if(i < 499)
	    ct = ct + ',';
    }
    cout << ct;
    for(i = 0; i < KEY_ROW; ++i)
        delete[] key[i];
    delete[] key;
    return ct;

}
#endif

string decipher3(int *ct, int length, int **key_d) {
	string s;
	int diff_count;
	int val_ch[27];
	int i, j, count_sum = 0, prev_ct = 150, prev2_ct = 150;
	const int rep_2[27] = {0,1,27,26,27,100,47,33,1,2,0,1,200,43,43,97,55,0,60,225,78,1,1,1,1,0,10};
	const int rep_3[27] = {0,0,0,0,0,180,0,0,0,720,0,0,0,0,0,0,0,0,0,0,0,0,0,0,180,0,0};
	const int rep_a2[27] = {1,14,2,26,99,70,2,46,7,10,2,2,15,13,18,8,8,2,74,596,47,5,2,2,2,5,2};
const int first_char[27] = {0, 42,42,42,42,42,42,41,41,42,41,42,41,41,41,41,41,41,42,41,42,42,42,42,41,42,41};
	const float min_dist[27]={2.76, 4.86786, 8.75568, 9.0553, 4.10477, 5.19616, 3.06224, 6.4442, 1.98702, 6.53757, 0.841487, 3.89966, 8.02397, 6.14385, 5.17745, 4.57832, 6.32145, 0.819469, 6.60706, 7.97804, 4.24963, 7.47525, 4.65403, 1.91895, 1.301, 3.7922, 1.96299};
//2.92368, 5.15992, 9.281, 9.59865, 4.35105, 5.50795, 3.24598, 6.83088, 2.10624, 6.92982, 0.891975, 4.13364, 8.5054, 6.5125, 5.48809, 4.85302, 6.70073, 0.868635, 7.00349, 8.45673, 4.50461, 7.92377, 4.93327, 2.03409, 1.37907, 4.01972, 2.08077};
	const float max_dist[27]={ 52.44, 34.075,8.75568,18.1106,16.4191,51.9616,6.12448,12.8884,9.9351,39.2254,0.841487,3.89966,24.0719,12.2877,31.0647,27.4699,12.6429,0.819469,33.0353,39.8902,29.7474,14.9505,4.65403,3.83791,1.301,7.5844,1.96299};
	float dist[27];
	int diff2, diff[27];
	cout << "For testcase2 \n\n";
	
	int *count = new int[106];
	for(j=0;j < 106;j++) {
		count[j] = 0;
	}
	for(j=0;j<27;j++) {
		key_d[106][j] += first_char[j] - 40;
		key_d[ct[i]][j] = first_char[j];
	}

	for(i =0;i < length ;i++) {
		if(prev2_ct == ct[i]) {
#ifdef DEBUG
			cout << "alternate alphabet same = " <<ct[i] << " at " << i << "\n";
#endif
			for(j=0;j<27;j++) {
				key_d[106][j] += rep_a2[j] - key_d[ct[i]][j];
				key_d[ct[i]][j] = rep_a2[j];
			}
		}
		prev2_ct = prev_ct;
		prev_ct = ct[i];
	}
	for(i =0;i < length ;i++) {
		if(prev_ct == ct[i]) {
#ifdef DEBUG
			cout << "same alphabet = " <<ct[i] << " at " << i << "\n";
#endif
			for(j=0;j<27;j++) {
				key_d[106][j] += rep_2[j] - key_d[prev_ct][j];
				key_d[prev_ct][j] = rep_2[j];
			}
		}
		prev_ct = ct[i];
	}

	for(i =0;i < length ;i++) {
		count[ct[i]]++;
		if(prev_ct == ct[i] && prev_ct == prev2_ct) {
#ifdef DEBUG
			cout << "alphabet repeated three times = " <<ct[i] << " at " << i << "\n";
#endif
			for(j=0;j<27;j++) {
				key_d[106][j] += rep_3[j] - key_d[prev_ct][j];
				key_d[prev_ct][j] = rep_3[j];
			}
		}
		prev2_ct = prev_ct;
		prev_ct = ct[i];
	}
	count_sum = 0;
	for(i =0;i < 106 ;i++) {
		//cout << (float)count[i]*106/count_sum << " ";
#ifdef DEBUG
		cout << " count = ";
		cout << (char)(96+i) << "  " << count[i] << ", ";
#endif
		if(count[i]) count_sum++;
		
	}
	//cout << " Total number of symbols = " << count_sum << endl;
	//cout << endl;
	//for(i =0;i < 27 ;i++) {
	//	cout << max_dist[i]/alphabet_weight[i] << "\n ";
	//}
	for(i=0;i<27;i++) {
		dist[i] = count_sum > 27 ? (max_dist[i] - (max_dist[i] - min_dist[i])/78*(count_sum-27)) : max_dist[i];
	}
	//cout <<"Distribution = " << endl;
	//for(i =0;i < 27 ;i++) {
	//	cout << dist[i] << "\n ";
	//}

//Possibility allocation depending upon the symbol distribution.
	for(i=0;i<27;i++) {
		if(count[i]) {
			diff2 = 0;
			diff_count = 0;
			for(j=0;j<27;j++)
				val_ch[j] = 0;
			for(j=0;j<27;j++) {
			    diff[j] = abs(count[i] - dist[j]);
			    if(diff[j] < 1) {
				val_ch[j] += 10;
				diff_count = diff_count + 10;
			    } else if(diff[j] < 2) {
				val_ch[j] += 5;
				diff_count = diff_count + 5;
			    } else if(diff[j] < 3) {
				val_ch[j] += 2;
				diff_count = diff_count + 2;
			    }else if(diff[j] < 4) {
				val_ch[j] += 1;
				diff_count++;
			    } else if(diff[j] < 7) {
				diff_count = diff_count;
			    } else if(diff[j] < 10) {
				val_ch[j] = (key_d[i][j] > 1) ? (int) -5 +(40 - key_d[i][j])/8 : 0;
				diff2 += (key_d[i][j] > 1) ? (int) 5  - (40 - key_d[i][j])/8 : 0;
			   } else if(diff[j] < 15) {
				val_ch[j] = (key_d[i][j] > 1) ? (int) -20 +(40 - key_d[i][j])/2 : 0;
				diff2 += (key_d[i][j] > 1) ? (int) 20 - (40 - key_d[i][j])/2 : 0;
			    } else {
				val_ch[j] = (key_d[i][j] > 1) ? (int) - 35 +(40 - key_d[i][j])*7/8 : 0;
				diff2 += (key_d[i][j] > 1) ? (int) 35  -(40 - key_d[i][j])*7/8 : 0;
			    }
			}
			prev_ct = diff2/diff_count;
			prev2_ct = diff2%diff_count;	
			for(j=0;j<27;j++) {
				if(val_ch[j]>4) {
				        val_ch[j] = val_ch[j]*prev_ct;
					val_ch[j] += prev2_ct;
					prev2_ct = 0;
				}
				else if(val_ch[j]>0) {
				   val_ch[j] = val_ch[j]*prev_ct;
				}
				//cout << "diff_count = " << diff_count << " diff = " << diff[j] << " val_ch = " <<val_ch[j]<< "     ";
			}
			//cout <<" mul factor = " << prev_ct << "reminder = " << prev2_ct << " count = " << count[i] << " diff2 = " << diff2 << endl;
			for(j=0;j<27;j++) {
				key_d[i][j] += val_ch[j];
			}
		}
	print_key2(key_d);
		
	}
	s = (string) no_output;
	return s;
}


