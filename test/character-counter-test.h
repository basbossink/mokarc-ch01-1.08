char *
test_count_character(void);


#define declare_test(t) char * test_count_characters_##t(void)

declare_test(a);
declare_test(b);
declare_test(c);
declare_test(d);
declare_test(e);
declare_test(f);
declare_test(g);
declare_test(h);

#undef declare_test
