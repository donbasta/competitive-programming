typedef struct item* pitem;
struct item {
  int prio, val, cnt;
  bool rev;
  pitem l, r;
}

int cnt (pitem it) {
  return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
  if (it)
    it->cnt = cnt (it->l) + cnt (it->r) + 1;
}

void push (pitem it) {
  if (it && it->rev) {
    it->rev = false;
    swap (it->l, it->r);
    if (it->l) it->l->rev ^= true;
    if (it->r) it->r->rev ^= true;
  }
}

void merge (pitem& t, pitem l, pitem r) {
  push (l), push (r);
  if (!l || !r) {
    t = l ? l : r;
  } else if (l->prio > r->prio) {
    merge (l->r, l->r, r), t = l;
  } else {
    merge (r->l, l, r->l), t = r;
  }
  upd_cnt (t);
}

void split (pitem t, pitem& l, pitem& r, int key, int add = 0) {
  if (!t) {
    return void (l = r = 0);
  } 
  push (t);
  int cur_key = add + cnt (t->l);
  if (key <= cur_key) {
    split (t->l, l, t->l, key, add), r = t;
  } else  {
    split (t->r, t->r, r, key, add + 1 + cnt (t->l)), l = t;
  }
  upd_cnt (t);
}

void reverse (pitem t, int l, int r) {
  pitem t1, t2, t3;
  split (t, t1, t2, l);
  split (t2, t2, t3, r - l + 1);
  t2->rev ^= true;
  merge (t, t1, t2);
  merge (t, t, t3);
}

