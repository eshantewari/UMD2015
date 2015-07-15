void exercise5(){
  double mass = 91.2;
  double lifetime = 2.5;
  TF1 *fa1 = new TF1("fa1","1/((x-91.2)*(x-91.2)+2.5/2)",0,100);
  fa1->Draw();
}
