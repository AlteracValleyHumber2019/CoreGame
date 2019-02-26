//#include <iostream>
//#include <thread>
//
//static bool s_finished = false;
//
////This is a simple function that can be called in a separate thread
//void DoWork()
//{
//	using namespace std::literals::chrono_literals;
//
//	while (!s_finished)
//	{
//		std::cout << "Working ... \n";
//		std::this_thread::sleep_for(1s);
//	}
//}
//
//
//int main()
//{
//	//Make a new thread and call it "worker". An overloaded constructor takes in a function pointer (the name of the method without any brackets)
//	std::thread worker(DoWork);
//
//	std::cin.get();
//	s_finished = true;
//
//	//Wait for the above thread to finish before execute another command line
//	//"Can you wait on the current thread for this thread to finish, so block the current thread until the worker thread is finished"
//	worker.join();
//
//	std::cout << "Finished";
//}