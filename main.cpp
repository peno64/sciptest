int main(int argc, const char *argv[])
{
	extern int sciptest1(int argc, const char *argv[]), sciptest2();

	sciptest1(argc, argv);
	sciptest2();

	return 0;
}