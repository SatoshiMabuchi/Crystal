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
	EXPECT_EQ("AAA", chain.getCurrentCommand()->getName());
}

TEST(CommandChainTest, TestForward)
{
	CommandChain chain;
	chain.setOrigin(new TestCommand("AAA"));
	EXPECT_EQ("AAA", chain.getCurrentCommand()->getName());
	chain.add(new TestCommand("BBB"));
	chain.forward();
	EXPECT_EQ("BBB", chain.getCurrentCommand()->getName());
}

TEST(CommandChainTest, TestBackward)
{
	CommandChain chain;
	chain.setOrigin(new TestCommand("AAA"));
	EXPECT_EQ("AAA", chain.getCurrentCommand()->getName());
	chain.add(new TestCommand("BBB"));
	chain.forward();
	EXPECT_EQ("BBB", chain.getCurrentCommand()->getName());
	chain.backward();
	EXPECT_EQ("AAA", chain.getCurrentCommand()->getName());
}