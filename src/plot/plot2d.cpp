#include "plot2d.h"

namespace Plotypus
{
    Plot2D::Plot2D(const std::string& title) :
        Plot(title)
    {
        type = PlotType::Plot2D;
    }

    Plot2D::~Plot2D()
    {
        for (auto dataView : dataViews)
        {
            delete dataView;
        }
    }

    // ====================================================================== //

    void Plot2D::reset()
    {
        Plot::reset();

        for (auto dataView : dataViews)
        {
            delete dataView;
        }

        dataViews.clear();
    }

    const std::vector<DataView*>& Plot2D::getDataViews() const
    {
        return dataViews;
    }

    DataView& Plot2D::dataView(const size_t i)
    {
        checkIndex("dataView index", i, dataViews);
        return *dataViews[i];
    }

    // ====================================================================== //
    // writers

    void Plot2D::preprocessSheet(const std::string& autoDataFilename, const std::string& extension) const
    {
        for (size_t i = 1u; const auto dataView : dataViews)
        {
            if (dataView->getAutoGenerateDataFilename())
            {
                const auto fullOutputFilename = autoDataFilename + "_" + std::to_string(i) + "." + extension;
                dataView->setDataFilename(fullOutputFilename);
            }
            ++i;
        }
    }

    void Plot2D::writeTxtData(std::ostream& hFile) const
    {
        Plot::writeTxtData(hFile);
        for (const auto dataView : dataViews)
        {
            hFile << datalineSeparatorTxt;
            dataView->writeTxtData(hFile);
        }
    }

    void Plot2D::writeDatData() const
    {
        Plot::writeDatData();
        for (const auto dataView : dataViews)
        {
            dataView->writeDatData();
        }
    }

    void Plot2D::writeScriptData(std::ostream& hFile) const
    {
        Plot::writeScriptData(hFile);

        hFile << "plot ";
        const auto viewCount = dataViews.size();
        for (size_t i = 0u; const auto dataView : dataViews)
        {
            dataView->writeScriptData(hFile);
            ++i;
            if (i < viewCount)
            {
                hFile << ", \\\n\t";
            }
        }
        hFile << std::endl;
    }

    void Plot2D::writeScriptFooter(std::ostream& hFile, int pageNum) const
    {
        Plot::writeScriptFooter(hFile, pageNum);
        hFile << std::endl;
    }
}
