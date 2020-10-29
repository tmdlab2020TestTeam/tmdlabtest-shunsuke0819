#include <stdio.h>

int total_num = 20;

// ターミナルにソートした結果を出力する
void show_data(int num[total_num]){
  for(int i=0; i<total_num; i++){
    printf("%d ", num[i]);
  }
  printf("\n");
}

/* クイックソート
   配列の1番目の要素以上のものを左から，未満のものを右から探す．
   左右で1つずつ見つかった場合，入れ替える．
   左右のキーがぶつかったら処理を左右に分け，その中で探索を継続する．*/
void quick_sort(int num[total_num], int left, int right){
  printf("クイックソート\n");
  int tmp;
  int pivot;                        // 探索基準の要素
  int l = left;                     // ソートする配列の一番小さい要素番号
  int r = right;                    // ソートする配列の一番大きい要素番号

  pivot = num[(left + right) / 2]; // 基準値を配列の中央付近にとる

  while(1){ 
    // pivotより大きい値が出るまでlを増加させる．
    // pivotより小さい値が出るまでrを減少させる．                                 
      if (l >= r)               // i>=jなら無限ループから抜ける．
        break;                 
      tmp = num[l];             // num[i]とnum[j]を交換する．
      num[l] = num[r];
      num[r] = tmp;         
      l++;                    
      r--;
    }
    show_data(num);              // 途中経過を表示
    if (left < l-1)              // 基準値の左に2以上要素があれば左の配列をソートする．
      quick_sort(num, left, l-1);     
    if (r+1 < right)            // 基準値の右に2以上要素があれば右の配列をソートする．
      quick_sort(num, r+1, right); 
}

// 5で割った時余りが出るもの
void remainder_number(int num[total_num]){
  printf("5で割った時余りが出るものを表示\n");
  int count=0;
  int remainder_num[total_num];
  // for文で回して，条件を満たした場合remainder_numに格納してcountを増やす．
  total_num = count;
  show_data(remainder_num);
  quick_sort(remainder_num, 0, total_num-1); // 配列，一番頭の配列番号，一番最後の配列番号
}

int main(void){

  // 以下データ読み込み用
  // num[20]に値を入れ込んでるだけなので，読まなくて大丈夫．
  FILE *fp;
  int num[total_num];
  fp = fopen("data.txt", "r");
  if(fp == NULL){
    printf("ファイルをオープンできませんでした。\n");
    return 0;
  }
  int count = 0;
  while(fscanf(fp, "%d", &num[count]) != EOF){
    count++;
  }
  fclose(fp);

  remainder_number(num);

  return 0;
}