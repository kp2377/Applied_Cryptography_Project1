#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string.h>
using namespace std;

#define KEY_ROW 27
#define KEY_COLUMN 19

//#define DEBUG

//#define AUTO


const char test_case[5][501] = {"masterwork swept squanders grounders idolatries swapper pave croupier dramatists magnified hypnoses delivery tassels marquise entailments circuits crampon nationalism nictitation anticapitalists dancingly soothly patriarchs goodie whickers baggy omnipotent sadist ameba processions beggary rename nonassertively macerators lectureship shipwrights sadden backups rhymer offstage schistose ebbs restorer graecizes subjoining leathering smocks leukocyte waled temperer embroglios bolivar repines teletyp", "wharves locoisms tearjerkers remiss chops duties prolonged inequities minnows itemized thematically scorecard deliverers jokingly semiosis claspers brazenness grateful collarbones stamping bittersweets habilitation endorsers decrepitly tambourine shadowboxes adopting ingenuous disquisitions quietist innovates mingles nationals disparaging exults realtor cockade rubberizing tubercled unremitting sloppiest algin knuckleball disengage domes doltishly encyclics spectroscopically debauched circumsola", "ozonise creosotes disruption neighborly lunier shagging balancing adriatic dick guesstimate storminess jest soberer spun toolbox crochet firebreak parliamentary undismayed lintiest homoeroticism silverfishes cornstalk digest subtler ruck cairns wombat working synapsed diamonding association opalescence crenation bumblebees undetected sandwiching unpeoples polishes schoolwork familarity flaying slued soothers splenification dare hydrology gourami alligators varsity statuettes gainly feeding filme", "autarky sartor terbium synapse herr eugenicists isthmian reembarks spinet dictaphone ecology carinae coeducational carburizing undulated twopenny subscriptions wrigglier scaliness enthrallingly carvers russified rejoice anaconda switzerland sallows devotedly pledgees incongruous miriest nonextraditable extrospection clipping souffle mimicry interrupts reputably reteaches quicksets bankroll hallucinated unzealous invocation winless yacking shinbone tonal vasoconstrictive manioc gourami purling ey", "championships iatrogenic maniacally antonym schoolboy shyly leafhoppers inturned sunbathing overrefined obliterations discus maintain cranked uniters twangled impairer wreakers forewings silesia occupance headroom foresting ornithologists shims lackaday benumbedness gloomy sententious fussing flagrant consonance profligately scutcheons honda swooned headworks zeins intermezzo adaptions elbow ocotillos denim japers thalamic corinthians restraightening kowtowed embarrasses latissimi impoverished s"};

#ifdef AUTO
int random_array[106] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105};
#endif
int alphabet_weight[27] = {19,7,1,2,4,10,2,2,5,6,1,1,3,2,6,6,2,1,5,5,7,2,1,2,1,2,1};

string cipher(const char * pt, int length);
void decipher(int *ct, int length, char *pt);
string decipher2(int *ct, int length, int ***key_decipher);
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
	return (string) "No testcase is matached with plaintext.";
    }
}

int main()
{
    int i,j,k,length,ct[500];
    string plaintext_2, s, symbol;
    clock_t start,end;
    float seconds;

    int ***key_decipher;

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
    
// Enter the plaintext
#ifdef AUTO    
    srand (time(NULL));
    length = 500;
    s = cipher(test_case[1], length);
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
    //cout<<"The randomly generated number is :"<<rg<<"\n";
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
	ct_int[i] = key[key_list][rand()%alphabet_weight[key_list]];
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
    return ct;

}
#endif


