#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Plotypus
{
//! @addtogroup Plotypus_Definitions
//! @{

    // ====================================================================== //
    /**
     * @brief used to assert filename valdity
     */

    constexpr static auto invalidFilenameChars = "*~|:;<> '\"";

    // ====================================================================== //
    /**
     * @brief convenience symbol to be used with setting data ranges
     */
    constexpr double AUTO_RANGE = std::numeric_limits<double>::quiet_NaN();

    // ====================================================================== //

    template <typename T>
    static inline double defaultDataSelector(const T& x)
    {
        return x;
    }

    // ====================================================================== //

    constexpr size_t COLUMN_UNUSED          = 0u;
    constexpr size_t COLUMN_UNSUPPORTED     = std::numeric_limits<size_t>::max();
    constexpr size_t COLUMN_LIST_INVALID    = 0u;

    constexpr auto COLUMN_FORMAT_PLACEHOLDER_COLUMN_NUMBER = '_';
    constexpr auto COLUMN_FORMAT_ESCAPE_INTERNAL_COLUMN_ID = '!';

    constexpr auto COLUMN_FORMAT_DEFAULT         = "_";
    constexpr auto COLUMN_FORMAT_FILTER_POSITIVE = "($_ >= 0 ? $_ : 1/0)";
    constexpr auto COLUMN_FORMAT_FILTER_NEGATIVE = "($_ <= 0 ? $_ : 1/0)";

//! @}
}

#endif // CONSTANTS_H