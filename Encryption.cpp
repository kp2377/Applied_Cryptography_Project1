//
//  main.cpp
//  applied_Cryptography
//
//  Created by kartikey purohit on 9/20/19.
//  Copyright © 2019 kartikey purohit. All rights reserved.
//

// my first program in C++
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


#define KEY_ROW 27
#define KEY_COLUMN 19

using namespace std;

void cipher(char * pt, int length, int **key, int *ct);

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
    rg = rand() % 106;
    if(rg>=76 && rg<=94)
    {
        rg = random_generator();
    }
    //cout<<"The randomly generated number is :"<<rg<<"\n";
    return rg;
}

void cipher(char *pt, int length, int **key, int *ct) {
    int alphabet_weight[27] = {19,7,1,2,4,10,2,2,5,6,1,1,3,2,6,6,2,1,5,5,7,2,1,2,1,2,1};
    cout<<"The key in Cipher : \n";
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
	cout << ct[i] << ",";

    }

}


int main()
{
    int i;
    int count;
    int length = 500;
    int random_array[106] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105};
    
    int alphabet_weight[27] = {19,7,1,2,4,10,2,2,5,6,1,1,3,2,6,6,2,1,5,5,7,2,1,2,1,2,1};
    int same_weight[20] =     { 0,7,8,1,1,3,3,2,0,0,1,0,0,0,0,0,0,0,0,1};
    int ciphertext[500];
    char plaintext[5][501] = {"so delightful up dissimilar by unreserved it connection frequently do an high room so in paid up on cousin ye dinner should in sex stood tried walls manor truth shy and three his their to years so child truth honoured peculiar families sensible up likewise by on in compliment interested discretion estimating on stimulated apartments oh dear so sing when in find read of call as distrusts behaviour abilities defective is never at water me might on formed merits hunted unable merely by mr whence or", "Had strictly mrs handsome mistaken cheerful We it so if resolution invitation remarkably unpleasant conviction As into ye then form To easy five less if rose were Now set offended own out required entirely Especially occasional mrs discovered too say thoroughly impossible boisterous My head when real no he high rich at with After so power of young as Bore year does has get long fat cold saw neat Put boy carried chiefly shy general And sir dare view but over man So at within mr to simple assure M", "Had strictly mrs handsome mistaken cheerful We it so if resolution invitation remarkably unpleasant conviction As into ye then form To easy five less if rose were Now set offended own out required entirely Especially occasional mrs discovered too say thoroughly impossible boisterous My head when real no he high rich at with After so power of young as Bore year does has get long fat cold saw neat Put boy carried chiefly shy general And sir dare view but over man So at within mr to simple assure M", "Had strictly mrs handsome mistaken cheerful We it so if resolution invitation remarkably unpleasant conviction As into ye then form To easy five less if rose were Now set offended own out required entirely Especially occasional mrs discovered too say thoroughly impossible boisterous My head when real no he high rich at with After so power of young as Bore year does has get long fat cold saw neat Put boy carried chiefly shy general And sir dare view but over man So at within mr to simple assure M", "Had strictly mrs handsome mistaken cheerful We it so if resolution invitation remarkably unpleasant conviction As into ye then form To easy five less if rose were Now set offended own out required entirely Especially occasional mrs discovered too say thoroughly impossible boisterous My head when real no he high rich at with After so power of young as Bore year does has get long fat cold saw neat Put boy carried chiefly shy general And sir dare view but over man So at within mr to simple assure M"};
    
    //int *key = (int *)calloc(KEY_ROW*KEY_COLUMN, sizeof(int));
    int** key = new int*[KEY_ROW];
    for(i = 0; i < KEY_ROW; ++i)
        key[i] = new int[KEY_COLUMN]; 
    
    //cout<<"The key initialized is : ";
    //for(int j=0;j<106;j++)
    //{
    //    cout<<*(key+j)<<'\n';
    //}
    
    cout<<"the initial weight is: "<<'\n';
    for(int i=0;i<27;i++)
    {
        cout<<"Number: "<<i<<" Value :";
        cout<<alphabet_weight[i]<<'\n';
    }
    
    //srand (time(NULL));
    
    int random_number;
    int temp1 = 0;
    
    for(int j=0;j<19;j++)
    {
        key[0][j] = 76+j;
    }   // Giving key as (<space>,1)= 76,(<space>,2)= 77....(<space>,19)= 94
    
    cout<<"The key initialized is : ";
    for(int j=0;j<106;j++)
    {
        cout<<key[j/KEY_COLUMN][j%KEY_COLUMN]<<'\n';
    }

    for(int k=0;k<500;k++)
    {
        if(temp1 == 75 ){temp1 = 95;}
        if(temp1 == 106 ){temp1 = 0;}
        random_number = random_generator();
        cout<<"The Value Finally received is: "<< random_number<<'\n';
        int temp2 = random_array[random_number];
        cout<<temp2<<" :random_array[random_number], ";
        random_array[random_number] = random_array[temp1];
        cout<< random_array[random_number]<<" :random_array[temp1], ";
        random_array[temp1] = temp2;
        cout<<random_array[temp1]<<" :temp2, ";
        cout<<temp1<<" :temp1\n";
        temp1++;
        
    }
    
    int counter = 0;
    for(int l=1;l<KEY_ROW;l++)
    {
        for(int m=0;m<alphabet_weight[l];m++)
        {
            if(counter == 76 ){counter = 95;}
            key[l][m] = random_array[counter];
            cout<<key[l][m]<<'\n';
            counter++;
            cout<<"The counter value is : "<<counter<<',';
        }
        cout<<'\n';
    }
    
    

    
    cout<< "Hi this is Kartikey!! The answer is :"<<'\n' ;
    
    
    cout<<"The final weights are: ";
    for(int i=0;i<27;i++)
    {
        cout<<alphabet_weight[i]<<'\n';
    }

    cout<<"The key initialized is : \n";
    print_key(key);

    cipher(plaintext[0], length, key, ciphertext);

    return 0;
}

