/*Patrick Anderson psa5dg 4102 Algorithms HW2*/

/*I used this website for a Merge Sort template:
http://quiz.geeksforgeeks.org/merge-sort/
I went to office hours on Thursday, 9/1, with Mark Floryan.
I also discussed this problem with
Torry Yang (ty5kj) and William Will (wbw4sv). */

// Divide by positives and negatives
// Sort by initial smallest in the positives (group evens)
// Sort by final largest in the negatives

#include <stdio.h>
#include <stdlib.h>

const void trailerMaker(int *before, int *after, int n);
const void mergeSort(int *before, int *after, int l, int r);
const void merge(int *before, int *after, int l, int m, int r);


int main(int argc, char *argv[]) {
  int n;
  FILE *input;


  input = fopen(argv[1], "r");
  while (1) {
    fscanf(input, "%d", &n);
    int before[n];
    int after[n];
    for (int i = 0; i < n; i++) {
      fscanf(input, "%d %d", &before[i], &after[i]);
    }
    mergeSort(before, after, 0, n-1);
    trailerMaker(before, after, n);
    if (feof(input)) break;
  }
  return 0;
}

const void trailerMaker(int *before, int *after, int n) {
  int trailerSize = before[0];
  int freeSpace = before[0];
  for (int i = 0; i < n; i++) {
    if(before[i] > freeSpace) {
      trailerSize += (before[i]-freeSpace);
      freeSpace += (before[i]-freeSpace);
    }
    freeSpace -= before[i];
    freeSpace += after[i];
  }
  printf("%d\n", trailerSize);
}


const void mergeSort(int *before, int *after, int l, int r) {
  if (l < r) {
    int m = l+(r-l)/2;

    mergeSort(before, after, l, m);
    mergeSort(before, after, m+1, r);

    merge(before, after, l, m, r);
  }
}


const void merge(int *before, int *after, int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int Lb[n1], Rb[n2], La[n1], Ra[n2];

  for(i = 0; i < n1; i++) {
    Lb[i] = before[l+i];
    La[i] = after[l+i];
  }
  for(j = 0; j < n2; j++) {
    Rb[j] = before[m+1+j];
    Ra[j] = after[m+1+j];
  }

  i = 0;
  j = 0;
  k = l;

  while(i < n1 && j < n2) {
    if(Lb[i] <= La[i] && Rb[j] <= Ra[j]) {
      if(Lb[i] <= Rb[j]) {
	before[k] = Lb[i];
	after[k] = La[i];
	i++;
      }
      else {
	before[k] = Rb[j];
	after[k] = Ra[j];
	j++;
      }
    }

    else if(Lb[i] <= La[i] && Rb[j] > Ra[j]) {
      before[k] = Lb[i];
      after[k] = La[i];
      i++;
    }

    else if(Lb[i] > La[i] && Rb[j] <= Ra[j]) {
      before[k] = Rb[j];
      after[k] = Ra[j];
      j++;
    }

    else if(Lb[i] > La[i] && Rb[j] > Ra[j]) {
      if(La[i] > Ra[j]) {
	before[k] = Lb[i];
	after[k] = La[i];
	i++;
      }
      else {
	before[k] = Rb[j];
	after[k] = Ra[j];
	j++;
      }
    }
    k++;
  }

  while(i < n1) {
    before[k] = Lb[i];
    after[k] = La[i];
    i++;
    k++;
  }

  while(j < n2) {
    before[k] = Rb[j];
    after[k] = Ra[j];
    j++;
    k++;
  }
    
}
