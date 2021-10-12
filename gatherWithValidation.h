#include <string>

namespace injectionAttacks
{
	/**
	 * A wrapper for the gather command that removes its vulnerabilities using blacklist validation.
	 */
    bool gatherWithBlacklist(std::string food, std::string storage);

	/**
	 * A wrapper for the gather command that removes its vulnerabilities using whitelist validation.
	 */
    bool gatherWithWhitelist(std::string food, std::string storage);
}
