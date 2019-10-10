#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "stdc++.h" 
using namespace std;

#define KEY_ROW 27
#define KEY_COLUMN 19
#define MAX_CHARACTERS 501
#define KEY_CASES 5

//#define AUTO
#define DEBUG

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Global Variables!!-------------------------------------------------------------------------------------------------*///
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char test_case[5][501] = {"masterwork swept squanders grounders idolatries swapper pave croupier dramatists magnified hypnoses delivery tassels marquise entailments circuits crampon nationalism nictitation anticapitalists dancingly soothly patriarchs goodie whickers baggy omnipotent sadist ameba processions beggary rename nonassertively macerators lectureship shipwrights sadden backups rhymer offstage schistose ebbs restorer graecizes subjoining leathering smocks leukocyte waled temperer embroglios bolivar repines teletyp","wharves locoisms tearjerkers remiss chops duties prolonged inequities minnows itemized thematically scorecard deliverers jokingly semiosis claspers brazenness grateful collarbones stamping bittersweets habilitation endorsers decrepitly tambourine shadowboxes adopting ingenuous disquisitions quietist innovates mingles nationals disparaging exults realtor cockade rubberizing tubercled unremitting sloppiest algin knuckleball disengage domes doltishly encyclics spectroscopically debauched circumsola","ozonise creosotes disruption neighborly lunier shagging balancing adriatic dick guesstimate storminess jest soberer spun toolbox crochet firebreak parliamentary undismayed lintiest homoeroticism silverfishes cornstalk digest subtler ruck cairns wombat working synapsed diamonding association opalescence crenation bumblebees undetected sandwiching unpeoples polishes schoolwork familarity flaying slued soothers splenification dare hydrology gourami alligators varsity statuettes gainly feeding filme","autarky sartor terbium synapse herr eugenicists isthmian reembarks spinet dictaphone ecology carinae coeducational carburizing undulated twopenny subscriptions wrigglier scaliness enthrallingly carvers russified rejoice anaconda switzerland sallows devotedly pledgees incongruous miriest nonextraditable extrospection clipping souffle mimicry interrupts reputably reteaches quicksets bankroll hallucinated unzealous invocation winless yacking shinbone tonal vasoconstrictive manioc gourami purling ey","championships iatrogenic maniacally antonym schoolboy shyly leafhoppers inturned sunbathing overrefined obliterations discus maintain cranked uniters twangled impairer wreakers forewings silesia occupance headroom foresting ornithologists shims lackaday benumbedness gloomy sententious fussing flagrant consonance profligately scutcheons honda swooned headworks zeins intermezzo adaptions elbow ocotillos denim japers thalamic corinthians restraightening kowtowed embarrasses latissimi impoverished s"};

int random_array[106] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105};    
int alphabet_weight[27] = {19,7,1,2,4,10,2,2,5,6,1,1,3,2,6,6,2,1,5,5,7,2,1,2,1,2,1};
int same_weight[20] =     { 0,7,8,1,1,3,3,2,0,0,1,0,0,0,0,0,0,0,0,1};
int ciphertext[5][501];
int** test_key;
int flag =0;




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Declarations!!-----------------------------------------------------------------------------------------------------*///
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cipher(const char pt[], int length, int **key, int *ct);
void decipher(int *ct, int length, char *pt);
void swap(int *a, int *b);
void quicksort(int arr[], int l_most, int r_most);
void removeDuplicates(int *arr, int n); 
void placement_and_occurance(const char test_case[]);





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Function Definition!!----------------------------------------------------------------------------------------------*///
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sorting function:- taken from  https://medium.com/human-in-a-machine-world/quicksort-the-best-sorting-algorithm-6ab461b5a9d0
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to run quicksort on an array of integers
// l_most is the leftmost starting index, which begins at 0
// r_most is the rightmost starting index, which begins at array length - 1
void quicksort(int arr[], int l_most, int r_most)
{
    // Base case: No need to sort arrays of length <= 1
    if (l_most >= r_most)
    {
        return;
    }
    
    // Choose pivot to be the last element in the subarray
    int pivot = arr[r_most];

    // Index indicating the "split" between elements smaller than pivot and 
    // elements greater than pivot
    int cnt = l_most;

    // Traverse through array from l to r
    for (int i = l_most; i <= r_most; i++)
    {
        // If an element less than or equal to the pivot is found...
        if (arr[i] <= pivot)
        {
            // Then swap arr[cnt] and arr[i] so that the smaller element arr[i] 
            // is to the left of all elements greater than pivot
            swap(&arr[cnt], &arr[i]);

            // Make sure to increment cnt so we can keep track of what to swap
            // arr[i] with
            cnt++;
        }
    }
      // NOTE: cnt is currently at one plus the pivot's index 
    // (Hence, the cnt-2 when recursively sorting the left side of pivot)
    quicksort(arr, l_most, cnt-2); // Recursively sort the left side of pivot
    quicksort(arr, cnt, r_most);   // Recursively sort the right side of pivot
}

// remove duplicates function taken from :-  https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-array-using-stl-in-c/
void removeDuplicates(int *arr, int n, int *copy) 
{ 
    vector<int> v(arr, arr + n); 
    vector<int>::iterator it; 
    int cnt=0;
    it = unique(v.begin(), v.end()); 
    v.resize(distance(v.begin(), it)); 
    //cout << "\nAfter removing duplicates:\n"; 
    for (it = v.begin(); it != v.end(); ++it)
    {
    	//cout << *it << ", ";
	copy[cnt] = *it;
	cnt++;
    }    
   cnt =0; 
   //cout << '\n';
} 

void placement_and_occurance(const char tc[], int compare)
{
    int *ct = (int*)calloc(27, sizeof(int)); 
    int i =0;
    for(i=0;i<MAX_CHARACTERS;i++)
    {
       switch(tc[i]){
	       case ' ': test_key[0][ct[0]] = i;ct[0]++;break;
	       case 'a': test_key[1][ct[1]] = i;ct[1]++;break;
	       case 'b': test_key[2][ct[2]] = i;ct[2]++;break;
               case 'c': test_key[3][ct[3]] = i;ct[3]++;break;
               case 'd': test_key[4][ct[4]] = i;ct[4]++;break;
	       case 'e': test_key[5][ct[5]] = i;ct[5]++;break;
	       case 'f': test_key[6][ct[6]] = i;ct[6]++;break;
	       case 'g': test_key[7][ct[7]] = i;ct[7]++;break;
               case 'h': test_key[8][ct[8]] = i;ct[8]++;break;
               case 'i': test_key[9][ct[9]] = i;ct[9]++;break;
	       case 'j': test_key[10][ct[10]] = i;ct[10]++;break;
	       case 'k': test_key[11][ct[11]] = i;ct[11]++;break;
	       case 'l': test_key[12][ct[12]] = i;ct[12]++;break;
               case 'm': test_key[13][ct[13]] = i;ct[13]++;break;
               case 'n': test_key[14][ct[14]] = i;ct[14]++;break;
	       case 'o': test_key[15][ct[15]] = i;ct[15]++;break;
	       case 'p': test_key[16][ct[16]] = i;ct[16]++;break;
	       case 'q': test_key[17][ct[17]] = i;ct[17]++;break;
               case 'r': test_key[18][ct[18]] = i;ct[18]++;break;
               case 's': test_key[19][ct[19]] = i;ct[19]++;break;
	       case 't': test_key[20][ct[20]] = i;ct[20]++;break;
	       case 'u': test_key[21][ct[21]] = i;ct[21]++;break;
	       case 'v': test_key[22][ct[22]] = i;ct[22]++;break;
               case 'w': test_key[23][ct[23]] = i;ct[23]++;break;
               case 'x': test_key[24][ct[24]] = i;ct[24]++;break;
	       case 'y': test_key[25][ct[25]] = i;ct[25]++;break;
               case 'z': test_key[26][ct[26]] = i;ct[26]++;break;	       
       }
    } 

    int** placements_test_one = new int*[KEY_ROW];
    for(i = 0; i <= KEY_ROW; ++i)
        placements_test_one[i] = new int[ct[i]];

    int** cipher_map_one = new int*[KEY_ROW];
    for(i = 0; i <= KEY_ROW; ++i)
        cipher_map_one[i] = new int[ct[i]];

    int** cipher_index_weight = new int*[KEY_ROW];
    for(i = 0; i <= KEY_ROW; ++i)
        cipher_index_weight[i] = new int[ct[i]];


#ifdef DEBUG
    cout<<"the counter_values are: "; 
    for(int i=0; i<KEY_ROW;i++){cout<<ct[i]<<" ";}
    cout<<"\n";
#endif

     for(i=0;i<KEY_ROW;i++)
     { 
	 int count = ct[i];
         for(int j=0;j<count;j++)
         {
	    placements_test_one[i][j]=test_key[i][j];
	    cipher_map_one[i][j] = ciphertext[compare][placements_test_one[i][j]];
         }
       	 quicksort(cipher_map_one[i],0,ct[i]-1);
	 removeDuplicates(cipher_map_one[i],ct[i],cipher_index_weight[i]);
     }
#ifdef DEBUG
      for(i=0;i<KEY_ROW;i++)
     {
	int j = 0;
     	while(cipher_map_one[i][j]!='\0')
	{
	  cout<<cipher_map_one[i][j]<<",";
	  j++;
	}
	cout<<"\n";
     }
#endif

  

     cout<<"The values are: ";
     flag =0;
     for(i=0;i<KEY_ROW;i++)
     {
	int j = 0;
     	while(cipher_index_weight[i][j]!='\0')
	{
	  cout<<cipher_index_weight[i][j]<<",";
	  j++;
	}
	cout<<"The index value are: "<<j;
	if(j<=alphabet_weight[i])flag++;
        cout<<flag<<',';	
     }	
}



void print_key(int **key) {
    int count = 0, count2 = 96;
    for(int j=0;j<513;j++)
    {
	cout.width(3);
        cout<< key[j/KEY_COLUMN][j%KEY_COLUMN]<<" ";
	if(key[j/KEY_COLUMN][j%KEY_COLUMN])
	    count++;
	if(j%KEY_COLUMN == KEY_COLUMN - 1) {
	    cout << " = " << (char)(count2++) << " " << count << "\n";
	    count = 0;
	}
    }
}


int random_generator()  // random generator function that excludes 76 to 94
{
    int rg;
    //srand (time(NULL));
    rg = rand() % 106;
    return rg;
}

void cipher(const char pt[], int length, int **key, int *ct) {
    int alphabet_weight[27] = {19,7,1,2,4,10,2,2,5,6,1,1,3,2,6,6,2,1,5,5,7,2,1,2,1,2,1};
    //cout<<"The key in Cipher : \n";
    print_key(key);
    cout << "pt = " << pt <<"\n";
    unsigned char pt_c;
    int count,i;
    int key_list;
    for(i=0;i<length;i++) {
	pt_c = pt[i];
	if(pt_c < 96)
	    key_list= 0;
	else
	    key_list = pt_c - 96;
      //cout << key_list << " ";	
	ct[i] = key[key_list][rand()%alphabet_weight[key_list]];
	cout << ct[i]<<",";
    }
    //cout << "\n";
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Main Function!!----------------------------------------------------------------------------------------------------*///
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int i, j;
    int count;
    int length = 500; 
    string input, symbol;

    int** key = new int*[KEY_ROW];
    for(i = 0; i < KEY_ROW; ++i)
        key[i] = new int[KEY_COLUMN]; 

      //initializing the test keys which have placements and total occurances. So, test_one_key[MAX_CHARACTERS] is going to have the occurance value
    test_key = new int*[KEY_ROW];
    for(i = 0; i <= KEY_ROW; ++i)
        test_key[i] = new int[MAX_CHARACTERS];

#ifdef AUTO
     
    //If you want to randomize the entire key at each iteration, uncomment this line.
    srand (time(NULL));
    
    int random_number;
    int temp1 = 0;   

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
    
    int counter = 0;
    for(int l=0;l<KEY_ROW;l++)
    {
        for(int m=0;m<alphabet_weight[l];m++)
        {
            //if(counter == 76 ){counter = 95;}
            key[l][m] = random_array[counter];
            cout<<key[l][m]<<'\n';
            counter++;
            cout<<"The counter value is : "<<counter<<',';
	}
	cout<<'\n';
    }    
    
    cout<<'\n';
    cout<<'\n';
    cout<<'\n';

    cipher(test_case[0], length, key, ciphertext[0]);
    cipher(test_case[1], length, key, ciphertext[1]);
    cipher(test_case[2], length, key, ciphertext[2]);
    cipher(test_case[3], length, key, ciphertext[3]);
    cipher(test_case[4], length, key, ciphertext[4]);

    placement_and_occurance(test_case[0],0);
    placement_and_occurance(test_case[1],1);
    placement_and_occurance(test_case[2],1);
    placement_and_occurance(test_case[3],3);
    placement_and_occurance(test_case[4],4);
   

#else
    cout << "Enter the ciphertext : ";
    cin >> input;
// Find the length of the plaintext and convert from string to integer
    length = input.length();
    #ifdef DEBUG
    cout<<"the length is: "<<length<<"\n";
    #endif
    for(i=0,j=0; i < input.length(); i++) {
	if(input[i]==',') {
	    	    ciphertext[0][j]=atoi(symbol.c_str());
	    #ifdef DEBUG
	    cout<<"The counter values are: "<<i<<" "<<j<<'\n';
	    cout<<ciphertext[0][j]<<',';
	    #endif
            j = j+1;
	    symbol.clear();
	} else {
	symbol = symbol + input[i];
	}
    }
    
#ifdef DEBUG
    cout <<"\n\n ct integer = " << i << " " << j << "\n";
    cout<<"The cipher finally stored is: \n";  
        for(i=0;i<500;i++) {
	cout << ciphertext[0][i] << ",";
    }
#endif



     placement_and_occurance(test_case[0],0);
    if(flag == 27){cout<<"My Gusess is:"<<test_case[0]<<'\n';return 0;}
    //else {cout<<"Not from plain_text 1"<<'\n';}
    placement_and_occurance(test_case[1],0);
    if(flag == 27){cout<<"My Gusess is:"<<test_case[1]<<'\n';return 0;}
    //else {cout<<"Not from plain_text 2"<<'\n';}


    placement_and_occurance(test_case[2],0);
    if(flag == 27){cout<<"My Gusess is:"<<test_case[2]<<'\n';return 0;}
    //else {cout<<"Not from plain_text 3"<<'\n';}


    placement_and_occurance(test_case[3],0);
    if(flag == 27){cout<<"My Gusess is:"<<test_case[3]<<'\n';return 0;}
    //else {cout<<"Not from plain_text 4"<<'\n';}


    placement_and_occurance(test_case[4],0);
    if(flag == 27){cout<<"My Gusess is:"<<test_case[4]<<'\n';return 0;}
    else {cout<<"None of them is correct!!"<<'\n';}


#endif

}


/*99,57,37,2,33,72,3,84,51,43,40,25,1,54,0,2,89,25,58,6,14,29,7,81,74,37,42,47,51,83,6,44,69,88,72,37,73,39,34,86,59,2,2,72,64,33,0,49,37,1,46,62,62,5,60,95,62,11,1,66,24,20,100,84,5,0,50,54,72,95,34,74,11,15,46,10,27,0,2,19,95,99,14,47,98,64,1,17,65,34,40,13,6,62,52,84,25,65,25,104,16,41,59,39,1,65,74,6,24,7,14,19,0,41,101,25,63,15,14,60,58,6,67,25,9,63,88,98,7,2,27,101,15,65,92,2,37,40,102,27,72,102,5,67,2,25,75,20,60,14,15,0,86,92,24,52,46,10,64,83,92,11,82,17,19,15,19,98,39,20,10,39,10,14,2,39,83,98,77,61,52,4,50,102,11,62,64,4,11,82,67,0,2,37,73,7,14,44,102,67,52,47,101,6,24,0,79,84,2,13,82,6,19,62,57,7,74,67,2,74,102,90,19,77,55,97,36,16,64,66,63,3,8,67,102,43,9,60,37,23,22,57,55,47,6,77,83,99,98,67,0,97,2,88,92,10,96,25,14,16,50,37,2,24,2,15,88,22,11,80,0,100,84,20,41,25,0,27,79,52,25,23,22,66,55,47,2,100,6,104,51,9,52,14,15,48,28,32,36,92,46,25,0,5,72,1,67,1,33,82,6,19,15,11,102,5,51,30,2,97,100,0,95,59,33,102,4,5,51,54,19,31,67,0,96,37,35,50,62,3,51,39,55,90,2,0,95,0,2,69,7,33,98,73,22,11,102,43,6,62,0,85,60,35,6,99,88,74,89,79,3,3,0,2,30,55,33,89,37,102,8,27,19,4,36,0,41,63,33,22,22,37,28,51,41,19,7,86,60,48,74,104,47,60,11,33,102,50,2,9,0,77,0,5,22,45,86,67,44,64,29,47,80,82,33,14,2,31,81,72,64,32,55,28,0,99,84,102,43,0,19,82,5,5,43,79,20,6,2,66,80,3,14,101,33,69,19,4,66,15,62,9,51,33,72,40,9,15,22,72,86,55,82,50,36,0,73,22,97,59,50,1,2,100,89,51,88,0,67,92,48,25,75,1,65,59,41,2,6,62*/
