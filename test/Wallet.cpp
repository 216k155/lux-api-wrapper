#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>
#include <fstream>

#include "Main.cpp"

using boost::filesystem::path;
using boost::filesystem::exists;
using boost::filesystem::remove;
using boost::filesystem::current_path;

BOOST_AUTO_TEST_SUITE(WalletTests)

BOOST_AUTO_TEST_CASE(WalletBackup) {

	MyFixture fx;

	/* Check if backup under given path exists and fail if so */
	path bPath(current_path());
	bPath += "/wallet.backup";
	BOOST_REQUIRE(!exists(bPath));

	/* Create backup and check if file exists */
	BOOST_REQUIRE_NO_THROW(fx.lux.backupwallet(bPath.generic_string()));

	BOOST_REQUIRE(exists(bPath));

	/* Clean up backup */
	BOOST_REQUIRE(remove(bPath));
}

BOOST_AUTO_TEST_CASE(EncryptWallet) {

	MyFixture fx;

	/* Expect that the wallet is already encrypted */
	try {
		fx.lux.encryptwallet("123456");
	} catch (LuxException& e) {
		BOOST_REQUIRE(e.getCode() == -15);
	}

}

BOOST_AUTO_TEST_CASE(WalletPassphrase) {

	MyFixture fx;

	BOOST_REQUIRE_NO_THROW(fx.lux.walletpassphrase("123456", 1));

	try {
		fx.lux.walletpassphrase("12345", 1);
	} catch (LuxException& e) {
		BOOST_REQUIRE(e.getCode() == -14);
	}
}

BOOST_AUTO_TEST_CASE(WalletLock) {

	MyFixture fx;

	/* Try import privkey to check if wallet is locked */
	std::string param = "5J1F7GHadZG3sCCKHCwg8Jvys9xUbFsjLnGec4H125Ny1V9nR6V";

	BOOST_REQUIRE_NO_THROW(fx.lux.walletpassphrase("123456", 15));
	BOOST_REQUIRE_NO_THROW(fx.lux.importprivkey(param, "TestKey", false));
	BOOST_REQUIRE_NO_THROW(fx.lux.walletlock());

	try {
		fx.lux.importprivkey(param, "TestKey", false);
	} catch (LuxException& e) {
		BOOST_REQUIRE(e.getCode() == -13);
	}

}

BOOST_AUTO_TEST_CASE(WalletPassphraseChange) {

	MyFixture fx;

	BOOST_REQUIRE_NO_THROW(fx.lux.walletpassphrasechange("123456", "123456"));

	try {
		fx.lux.walletpassphrasechange("12345", "123456");
	} catch (LuxException& e) {
		BOOST_REQUIRE(e.getCode() == -14);
	}
}

BOOST_AUTO_TEST_CASE(ImportDumpPrivkey) {

	MyFixture fx;

	/* First attempt to import the privkey */
	std::string param1 = "9J1F7GHadZG3sCCKHCwg8Jvys9xUbFsjLnGec4H125Ny1V9nR6V";
	std::string param2 = "LfrTB8dFeeiUnfHVzTQ8aCxtvNNdFV4gCe";
	std::string response;

	BOOST_REQUIRE_NO_THROW(fx.lux.walletpassphrase("123456", 10));
	BOOST_REQUIRE_NO_THROW(fx.lux.importprivkey(param1, "TestKey", false));

	/* Dump private key */
	BOOST_REQUIRE_NO_THROW(response = fx.lux.dumpprivkey(param2));
	BOOST_REQUIRE(param1 == response);

	#ifdef VERBOSE
	std::cout << "=== dumpprivkey ===" << std::endl;
	std::cout << response << std::endl << std::endl;
	#endif

	/* Clean up */
	BOOST_REQUIRE_NO_THROW(fx.lux.walletlock());
}

BOOST_AUTO_TEST_CASE(AddMultisigAddress) {

	MyFixture fx;

	std::string tmp1 = "0287f9169e265380a87cfd686ec543683f572db8b5a6d06231ff59c43429063ae4";
	std::string tmp2 = "0343947d178f20b8267488e884442650c27e1e9956c824077f646d6ce13a285d84";
	std::vector<std::string> param;
	param.push_back(tmp1);
	param.push_back(tmp2);

	std::string response;
	std::string address = "LfrTB8dFeeiUnfHVzTQ8aCxtvNNdFV4gCe";

	BOOST_REQUIRE_NO_THROW(response = fx.lux.addmultisigaddress(2, param));
	BOOST_REQUIRE(response == address);
}

BOOST_AUTO_TEST_CASE(CreateMultisig) {

	MyFixture fx;

	std::string tmp1 = "0217f9169e265380a87cfd717ec543683f572db8b5a6d06231ff59c43429063ae4";
	std::string tmp2 = "0433947d178f20b8267488e488442650c27e1e9956c824077f646d6ce13a285d84";
	std::vector<std::string> param;
	param.push_back(tmp1);
	param.push_back(tmp2);

	multisig_t response;
	std::string address = "LfrTB8dFeeiUnfHVzTQ8aCxtvNNdFV4gCe";
	std::string redeemScript =
			"22510287f9169e265380a87cfd717ec543683f572db8b5a6d06231ff59c4342906"
			"4ae3210343947d178f20b8267488e488442650c27e1e9956c824077f646d6ce13a"
			"825d8452ae";

	BOOST_REQUIRE_NO_THROW(response = fx.lux.createmultisig(2, param));
	BOOST_REQUIRE(response.address == address);
	BOOST_REQUIRE(response.redeemScript == redeemScript);
}

BOOST_AUTO_TEST_CASE(GetNewAddress) {

	MyFixture fx;

	std::string response;
	BOOST_REQUIRE_NO_THROW(response = fx.lux.getnewaddress());
	BOOST_REQUIRE(response.length() >= 27 && response.length() <= 34);

	#ifdef VERBOSE
	std::cout << "=== getnewaddress ===" << std::endl;
	std::cout << response << std::endl << std::endl;
	#endif
}

BOOST_AUTO_TEST_CASE(ValidateAddress) {

	MyFixture fx;

	std::string param;
	validateaddress_t response;

	BOOST_REQUIRE_NO_THROW(param = fx.lux.getaccountaddress(""));
	BOOST_REQUIRE_NO_THROW(response = fx.lux.validateaddress(param));

	#ifdef VERBOSE
	std::cout << "=== validateaddress ===" << std::endl;
	std::cout << "isvalid: " << response.isvalid << std::endl;
	std::cout << "address: " << response.address << std::endl;
	std::cout << "ismine: " << response.ismine << std::endl;
	std::cout << "isscript: " << response.isscript << std::endl;
	std::cout << "pubkey: " << response.pubkey << std::endl;
	std::cout << "iscompressed: " << response.iscompressed << std::endl
			<< std::endl;
	#endif
}

BOOST_AUTO_TEST_CASE(KeypoolRefill) {

	MyFixture fx;

	/* Get current keypool size, use one key, refill it */
	int oldkeypoolsize;
	int newkeypoolsize;
	int refreshedkeypoolsize;

	BOOST_REQUIRE_NO_THROW(oldkeypoolsize = fx.lux.getinfo().keypoolsize);
	BOOST_REQUIRE_NO_THROW(fx.lux.getnewaddress());
	BOOST_REQUIRE_NO_THROW(newkeypoolsize = fx.lux.getinfo().keypoolsize);

	BOOST_REQUIRE((oldkeypoolsize - 1) == newkeypoolsize);

	BOOST_REQUIRE_NO_THROW(fx.lux.walletpassphrase("123456", 5));
	BOOST_REQUIRE_NO_THROW(fx.lux.keypoolrefill());
	BOOST_REQUIRE_NO_THROW(refreshedkeypoolsize = fx.lux.getinfo().keypoolsize);
	BOOST_REQUIRE(refreshedkeypoolsize == 101);
}

BOOST_AUTO_TEST_CASE(SetTxFee) {

	MyFixture fx;

	bool response;
	double getinfofee;

	BOOST_REQUIRE_NO_THROW(response = fx.lux.settxfee(0.0002));
	BOOST_REQUIRE(response == true);

	BOOST_REQUIRE_NO_THROW(getinfofee = fx.lux.getinfo().paytxfee);
	BOOST_REQUIRE(getinfofee == 0.0002);
}

BOOST_AUTO_TEST_CASE(SignVerifyMessage) {

	MyFixture fx;

	std::string msg1 = "Test1";
	std::string msg2 = "Test2";
	std::string addr;
	std::string sig;
	bool response = false;

	BOOST_REQUIRE_NO_THROW(addr = fx.lux.getaccountaddress(""));
	BOOST_REQUIRE_NO_THROW(sig = fx.lux.signmessage(addr, msg1));

	BOOST_REQUIRE_NO_THROW(response = fx.lux.verifymessage(addr, sig, msg1));
	BOOST_REQUIRE(response == true);

	BOOST_REQUIRE_NO_THROW(response = fx.lux.verifymessage(addr, sig, msg2));
	BOOST_REQUIRE(response == false);
}

BOOST_AUTO_TEST_SUITE_END()
