/*
Assignment 1
Louis Condevaux
C2305172
Data Structures and Algorithms
Section 1
Rene German
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include <math.h>

using namespace std;


int main (int argc, char ** argv){

  char User;
  string line, bigram, bigram2, totalBigram;
  double count, countA, countC, countT, countG, iteration, total, counti, sum;
  double aa, at, ag, ac, tt, tg, tc, ta, gg, gc, ga, gt, cc, ca, ct, cg;
  double proba_aa, proba_at, proba_ag, proba_ac, proba_tt, proba_tg, a, b,
  c,d, mu, var, log_a,
  proba_tc, proba_ta, proba_gg, proba_gc, proba_ga, proba_gt, proba_cc, proba_ca, proba_ct, proba_cg,
  probaA, probaC, probaT, probaG;
  double dnaMean, standard_dev, variance, proba;
  int bigramcount,l, stringLength;
  const double PI  = 3.141592653589793238463;

  srand (time(NULL)); //initializing random seed feed

  string term = argv[1]; //giving the name of the file at the terminal level

  std::ofstream myFile; //Creating my file to copy results
  myFile.open ("LouisCondevaux.out", std::ofstream::out | std::ofstream::trunc); //clearing my file
  myFile.close();
  myFile.open ("LouisCondevaux.out", std::ofstream::out | std::ofstream::app); //Opening my file


  ifstream dnaFile (term);//Passing my parameter

  if (dnaFile.is_open())
  {
    //myFile.open ("LouisCondevaux.out", std::ofstream::out | std::ofstream::trunc);
    count = 0;
    countA = 0, countC = 0, countG = 0, countT =0;
    variance = 0.0;

    while (getline(dnaFile, line)) //read from the file, first iteration
    {
      l = line.length(); //length of the line

      for(int i=0; i < l;i++) //looping in the file to count the bigrams
      {
        bigram = toupper(line[i]);
        bigram2 = toupper(line[i+1]);
        totalBigram = bigram + bigram2;
        totalBigram;

        if (totalBigram == "AA"){
          aa++;
          bigramcount++;
        }
        if (totalBigram =="AT")
        {
          at++;
          bigramcount++;
        }
        if (totalBigram =="AG")
        {
          ag++;
          bigramcount++;
        }
        if (totalBigram =="AC")
        {
          ac++;
          bigramcount++;
        }
        if (totalBigram =="TT")
        {
          tt++;
          bigramcount++;
        }
        if (totalBigram =="TG")
        {
          tg++;
          bigramcount++;
        }
        if (totalBigram =="TC")
        {
          tc++;
          bigramcount++;
        }
        if (totalBigram =="TA")
        {
          ta++;
          bigramcount++;
        }
        if (totalBigram =="GG")
        {
          gg++;
          bigramcount++;
        }
        if (totalBigram =="GC")
        {
          gc++;
          bigramcount++;
        }
        if (totalBigram =="GA")
        {
          ga++;
          bigramcount++;
        }
        if (totalBigram =="GT")
        {
          gt++;
          bigramcount++;
        }
        if (totalBigram =="CC")
        {
          cc++;
          bigramcount++;
        }
        if (totalBigram =="CA")
        {
          ca++;
          bigramcount++;
        }
        if (totalBigram =="CT")
        {
          ct++;
          bigramcount++;
        }
        if (totalBigram == "CG")
        {
          cg++;
          bigramcount++;
        }
      //cout <<totalBigram<<endl;
      }
      iteration ++;
      for (int i =0; i < l; i++) //second iteration to look at each individual character
      {
        char strInput = tolower(line[i]); //lower caps
        count++;

        if (strInput =='a')
        {
          countA++;
          total += countA;
        }
        if (strInput =='c')
        {
          countC++;
          total += countC;
        }
        if (strInput =='t')
        {
          countT++;
          total += countT;
        }
        if (strInput =='g')
        {
          countG++;
        total += countG;
        }
       }

       //double dnaMean = count /iteration; //calculating the mean
      // cout << "The line number is: " << iteration << "\n" << endl;
      // cout << "The length of the line is: " << line.length() << "\n" << endl;
      //cout << "The mean of the line is: " << dnaMean << "\n" << endl;
      //cout <<  "The total is: " << count << "\n" << endl;
    }

    probaA = (countA/ count)*100;
    probaC = (countC/ count)*100;     //relative probability of each
    probaT = (countT/ count)*100;
    probaG = (countG/ count)*100;

    proba_aa = (aa/bigramcount)*100;
    proba_at = (at/bigramcount)*100;
    proba_ag = (ag/bigramcount)*100;
    proba_ac = (ac/bigramcount)*100;
    proba_tt = (tt/bigramcount)*100;
    proba_tg = (tg/bigramcount)*100;
    proba_tc = (tc/bigramcount)*100;
    proba_ta = (ta/bigramcount)*100;
    proba_gg = (gg/bigramcount)*100;
    proba_gc = (gc/bigramcount)*100;
    proba_ga = (ga/bigramcount)*100;
    proba_gt = (gt/bigramcount)*100;
    proba_cc = (cc/bigramcount)*100;
    proba_ca = (ca/bigramcount)*100;
    proba_ct = (ct/bigramcount)*100;
    proba_cg = (cg/bigramcount)*100;

    dnaMean = count /iteration; //calculating the mean

    for ( double i = 0; i<count; ++i) //calculating variance and standard deviation
      variance += pow((i-dnaMean),2);
      variance = variance/count;
      standard_dev = sqrt(variance);

    dnaFile.close();
  }else
  {
    cout <<"Didn't work"<< endl;
  }
  if (myFile.is_open()) //copying results inside another recipient
  {
    myFile << "Louis Condevaux" << "\n" << "Student ID: C2305172" << "\n" << "Section 1"<< "\n" << endl;
    myFile << "the sum is: " << count << "\n";
    myFile << "the mean is: " << dnaMean << "\n";
    myFile << "The standard deviation is: " << standard_dev << "\n" << endl;
    myFile << "The variance is: " << variance << "\n" << endl;
    myFile << "The relative probability of A is: " << probaA << "%" << endl;
    myFile << "The relative probability of C is: " << probaC << "%" << endl;
    myFile << "The relative probability of T is: " << probaT << "%" << endl;
    myFile << "The relative probability of G is: " << probaG << "%" << "\n" << endl;
    myFile << "The relative probability of AA is: " << proba_aa << "%" << endl;
    myFile << "The relative probability of AT is: " << proba_at << "%" << endl;
    myFile << "The relative probability of AG is: " << proba_ag << "%" << endl;
    myFile << "The relative probability of AC is: " << proba_ac << "%" << endl;
    myFile << "The relative probability of TT is: " << proba_tt << "%" << endl;
    myFile << "The relative probability of TG is: " << proba_tg << "%" << endl;
    myFile << "The relative probability of TC is: " << proba_tc << "%" << endl;
    myFile << "The relative probability of TA is: " << proba_ta << "%" << endl;
    myFile << "The relative probability of GG is: " << proba_gg << "%" << endl;
    myFile << "The relative probability of GC is: " << proba_gc << "%" << endl;
    myFile << "The relative probability of GA is: " << proba_ga << "%" << endl;
    myFile << "The relative probability of GT is: " << proba_gt << "%" << endl;
    myFile << "The relative probability of CC is: " << proba_cc << "%" << endl;
    myFile << "The relative probability of CA is: " << proba_ca << "%" << endl;
    myFile << "The relative probability of CT is: " << proba_ct << "%" << endl;
    myFile << "The relative probability of CG is: " << proba_cg << "%" << endl;

    for (int i=1; i< 1000;++i) //calculate the gaussian distribution
    {

      mu = dnaMean;
      var = variance;
      a = ((double) rand() / (RAND_MAX));
      b = ((double) rand() / (RAND_MAX));
      log_a = log2(a);
      c = sqrt(-2*log_a) * (cos((2*PI)*b));
      d = (sqrt(1))*c + 0;

      for (int j=0; j< d; ++j){ //appending letters based on their previous frequency
        {
          int CompareProba = rand() %100 +1;
          if (CompareProba < probaA)
            myFile<< "a"<<"\n";
          else if (CompareProba < (probaA + probaC))
            myFile << "c"<<"\n";
            //cout << "c"<<endl;
          else if (CompareProba < (probaA + probaC + probaT))
            myFile << "t"<<"\n";
            //cout << "t"<<endl;
          else
            //cout << "g"<<endl;
            myFile << "g" <<"\n";

        }
      }
    }
    myFile.close();


    bool loop = true;
    while (loop){ //asking what the user wants to do after his first file has been processed
      cout << "Your results are waiting for you in the file you've chosen."<<endl;
      cout <<"Do you want to try with another file? [Y/N]"<< endl;

      cin >> User;
      User = toupper(User);

      if (User == 'Y'){
        cout << "Please enter the name of your file."<< endl;
        cin >> term;
        cout << "The name of the file you uploaded is: " << term << endl;

        ifstream dnaFile (term);
        if (dnaFile.is_open())
        {
          count = 0;
          countA = 0, countC = 0, countG = 0, countT =0;
          variance = 0.0;
          standard_dev = 0;
          probaA = 0;
          probaC = 0;
          probaT = 0;
          probaG = 0;
          proba_aa = 0;
          proba_ac = 0;
          proba_ag = 0;
          proba_at = 0;
          proba_tt = 0;
          proba_tg = 0;
          proba_tc = 0;
          proba_ta = 0;
          proba_gg = 0;
          proba_gc = 0;
          proba_ga = 0;
          proba_gt = 0;
          proba_cc = 0;
          proba_ca = 0;
          proba_ct = 0;
          proba_cg = 0;

          while (getline(dnaFile, line)) //read from the file, first iteration
          {
            l = line.length(); //length of the line

            for(int i=0; i < l;i++)
            {
              bigram = toupper(line[i]);
              bigram2 = toupper(line[i+1]);
              totalBigram = bigram + bigram2;
              totalBigram;

              if (totalBigram == "AA"){
                aa++;
                bigramcount++;
              }
              if (totalBigram =="AT")
              {
                at++;
                bigramcount++;
              }
              if (totalBigram =="AG")
              {
                ag++;
                bigramcount++;
              }
              if (totalBigram =="AC")
              {
                ac++;
                bigramcount++;
              }
              if (totalBigram =="TT")
              {
                tt++;
                bigramcount++;
              }
              if (totalBigram =="TG")
              {
                tg++;
                bigramcount++;
              }
              if (totalBigram =="TC")
              {
                tc++;
                bigramcount++;
              }
              if (totalBigram =="TA")
              {
                ta++;
                bigramcount++;
              }
              if (totalBigram =="GG")
              {
                gg++;
                bigramcount++;
              }
              if (totalBigram =="GC")
              {
                gc++;
                bigramcount++;
              }
              if (totalBigram =="GA")
              {
                ga++;
                bigramcount++;
              }
              if (totalBigram =="GT")
              {
                gt++;
                bigramcount++;
              }
              if (totalBigram =="CC")
              {
                cc++;
                bigramcount++;
              }
              if (totalBigram =="CA")
              {
                ca++;
                bigramcount++;
              }
              if (totalBigram =="CT")
              {
                ct++;
                bigramcount++;
              }
              if (totalBigram == "CG")
              {
                cg++;
                bigramcount++;
              }
            }
            iteration ++;
            for (int i =0; i < l; i++) //second iteration to look at each individual character
            {
              char strInput = tolower(line[i]); //lower caps
              count++;

              if (strInput =='a')
              {
                countA++;
                total += countA;
              }
              if (strInput =='c')
              {
                countC++;
                total += countC;
              }
              if (strInput =='t')
              {
                countT++;
                total += countT;
              }
              if (strInput =='g')
              {
                countG++;
              total += countG;
              }
             }
          }
          probaA = (countA/ count)*100;
          probaC = (countC/ count)*100;
          probaT = (countT/ count)*100;
          probaG = (countG/ count)*100;
          proba_aa = (aa/bigramcount)*100;
          proba_at = (at/bigramcount)*100;
          proba_ag = (ag/bigramcount)*100;
          proba_ac = (ac/bigramcount)*100;
          proba_tt = (tt/bigramcount)*100;
          proba_tg = (tg/bigramcount)*100;
          proba_tc = (tc/bigramcount)*100;
          proba_ta = (ta/bigramcount)*100;
          proba_gg = (gg/bigramcount)*100;
          proba_gc = (gc/bigramcount)*100;
          proba_ga = (ga/bigramcount)*100;
          proba_gt = (gt/bigramcount)*100;
          proba_cc = (cc/bigramcount)*100;
          proba_ca = (ca/bigramcount)*100;
          proba_ct = (ct/bigramcount)*100;
          proba_cg = (cg/bigramcount)*100;

          dnaMean = count /iteration; //calculating the mean
          for ( double i = 0; i<count; ++i)
            variance += pow((i-dnaMean),2);
            variance = variance/count;
            standard_dev = sqrt(variance);
          dnaFile.close();
        }else
        {
          cout <<"Didn't work"<< endl;
        }
        myFile.open ("LouisCondevaux.out", std::ofstream::out | std::ofstream::app); //clearing my file
        if (myFile.is_open()) //appending every results to the output file
        {
          //cout <<"lololol"<<endl; //making sure my file was opening
          myFile <<"\n";
          myFile << "the sum is: " << count << "\n";
          myFile << "the mean is: " << dnaMean << "\n";
          myFile << "The standard deviation is: " << standard_dev << "\n" << endl;
          myFile << "The variance is: " << variance << "\n" << endl;
          myFile << "The relative probability of A is: " << probaA << "%" << endl;
          myFile << "The relative probability of C is: " << probaC << "%" << endl;
          myFile << "The relative probability of T is: " << probaT << "%" << endl;
          myFile << "The relative probability of G is: " << probaG << "%" << "\n" << endl;
          myFile << "The relative probability of AA is: " << proba_aa << "%" << endl;
          myFile << "The relative probability of AT is: " << proba_at << "%" << endl;
          myFile << "The relative probability of AG is: " << proba_ag << "%" << endl;
          myFile << "The relative probability of AC is: " << proba_ac << "%" << endl;
          myFile << "The relative probability of TT is: " << proba_tt << "%" << endl;
          myFile << "The relative probability of TG is: " << proba_tg << "%" << endl;
          myFile << "The relative probability of TC is: " << proba_tc << "%" << endl;
          myFile << "The relative probability of TA is: " << proba_ta << "%" << endl;
          myFile << "The relative probability of GG is: " << proba_gg << "%" << endl;
          myFile << "The relative probability of GC is: " << proba_gc << "%" << endl;
          myFile << "The relative probability of GA is: " << proba_ga << "%" << endl;
          myFile << "The relative probability of GT is: " << proba_gt << "%" << endl;
          myFile << "The relative probability of CC is: " << proba_cc << "%" << endl;
          myFile << "The relative probability of CA is: " << proba_ca << "%" << endl;
          myFile << "The relative probability of CT is: " << proba_ct << "%" << endl;
          myFile << "The relative probability of CG is: " << proba_cg << "%" << endl;

          for (int i=1; i< 1000;++i) //calculate the gaussian distribution
          {
            mu = dnaMean;
            var = variance;
            a = ((double) rand() / (RAND_MAX));
            b = ((double) rand() / (RAND_MAX));
            log_a = log2(a);
            c = sqrt(-2*log_a) * (cos((2*PI)*b));
            d = (sqrt(1))*c + 0;
            for (int j=0; j< d; ++j){
                int CompareProba = rand() %100 +1;
                if (CompareProba < probaA)
                  myFile<< "a"<<"\n";
                else if (CompareProba < (probaA + probaC))
                  myFile << "c"<<"\n";
                else if (CompareProba < (probaA + probaC + probaT))
                  myFile << "t"<<"\n";
                else
                  myFile << "g" <<"\n";
              }
            }
          }
      }
      else if (User == 'N'){ //end of the loop
        cout<< "You are done for today"<< endl;
        loop = false;
      }
      else{ //end of the loop if the input was not y or n
        cout<< "The input was not valid, try again."<< endl;
        loop = false;
      }
    }
  }
  else{
    cout << "Didn't work my man"<< endl; //error check
  }
  dnaFile.close(); //closing both files
  myFile.close();
  return 0;
  }
