#include "gtest\gtest.h"
#include "../UI/CommandChain.h"

using namespace Crystal::UI;

namespace {
	class TestCommand : public IUICommand
	{
	public:
		explicit TestCommand(const std::string& name) :
			IUICommand(name)
		{}

		bool isCompleted() const override {
			return true;
		}

	private:
	};
}


TEST(CommandChainTest, TestSetOrigin)
{
	CommandChain chain;
	chain.setOrigin(new TestCommand("AAA"));
//	chain.forward();
	EXPECT_EQ("AAA", chain.getCurrentCommand()->getName());
	//chain.forward();
	//chain.add(new TestCommand("BBB"));
	//chain.forward();
}