#ifndef TYPES_H
#define TYPES_H

#include <cmath>
#include <functional>
#include <limits>
#include <string>

#include "constants.h"

namespace Plotypus
{
    //! @addtogroup Plotypus_Definitions
    //! @{

    // ====================================================================== //
    /**
     * @brief specifies script output data type
     */
    enum class FileType
    {
        Pdf,
        Png,
        PostScript,
        Gif
    };

    // ====================================================================== //
    /**
     * @brief internally used specifyer of data format
     */
    enum class PlotType
    {
        //! @brief an empty sheet, optionally with title. Ready to be populated with overlays
        Sheet,

        //! @brief functionality of sheet, together with frame formatting and capacity to accept 2D data sequences
        Plot2D,
        //! @brief same, but accepts 3D data sequences
        Plot3D,
        //! @brief same, but renders the z data as coloured pixels
        PlotColormap,

        //! @brief a sheet with multiple subsheets on it
        FramesCollection
    };

    // ---------------------------------------------------------------------- //
    /**
     * @brief used to compactly describe an axis of a plot
     */
    struct AxisDescriptor
    {
        std::string label          = "";
        std::string labelOptions   = "";
        bool        tics           = true;
        //! @todo std::vector<std::pair<std::string, double>> labels;
        //! @todo std::string formatstring
        //! @todo bool logscale
        std::string ticsOptions    = "";
        double      rangeMin       = 0;
        double      rangeMax       = AUTO_RANGE;
        int         rangeStride    = 1;
        std::string rangeOptions   = "";
    };

    // ====================================================================== //
    /**
     * @brief data selector: takes an object of type T and extracts the
     *  plottable quantity of type double
     */

    template <typename T>
    using DataSelector_t = std::function<double (const T&)>;

    // ====================================================================== //
    /**
     * @brief foo bar
     */
    enum class ColumnTypes
    {
        Column1,
        Column2,
        Column3,
        Column4,
        Column5,
        Column6,

        X, Y, Y2, Z,
        DeltaX, DeltaY, DeltaZ,
        XLow, XHigh, YLow, YHigh,
        Pointsize, Pointtype, Color,

        Boxwidth,

        Length, Angle
    };

    // ---------------------------------------------------------------------- //

    template <typename T>
    using columnSelectorList_t      = std::array<DataSelector_t<T>, 6>;
    using columnAssignmentList_t    = std::array<size_t, 6>;
    using columnFormatList_t        = std::array<std::string, 6>;

    //! }
}

#endif // TYPES_H
