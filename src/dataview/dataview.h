#ifndef DATAVIEW_H
#define DATAVIEW_H

#include <string>

namespace Plotypus
{
    class DataView
    {
        protected:
            PlotStyle2D styleID;

            std::string label;
            std::string style;
            std::string options = "";
            mutable std::string dataFilename = "";

            bool binaryDataOutput = true;
            bool autoGenerateDataFilename = true;

        public:
            DataView(const PlotStyle2D  style, const std::string& label = "");
            DataView(const std::string& style, const std::string& label = "");

            virtual void reset();

            const std::string&  getLabel() const;
            void                setLabel(const std::string& newLabel);

            const std::string&  getStyle() const;
            void                setStyle(const std::string& newStyle);

            const PlotStyle2D   getStyleID() const;
            void                setStyleID(const PlotStyle2D newStyle);

            bool                getBinaryDataOutput() const;
            void                setBinaryDataOutput(bool newBinaryDataOutput);

            const std::string&  getOptions() const;
            void                setOptions(const std::string& newOptions);

            bool                getAutoGenerateDataFilename() const;
            void                setAutoGenerateDataFilename(bool newAutoGenerateDataFilename);
            const std::string&  getDataFilename() const;
            void                setDataFilename(const std::string& newDataFilename) const;

            virtual bool isFunction() const = 0;
            virtual bool isDummy() const = 0;
            virtual bool isComplete() const = 0;

            virtual size_t getColumnID(const ColumnTypes columnType) const = 0;

            // -------------------------------------------------------------- //
            // writers

            virtual void writeDatData() const = 0;
            virtual void writeScriptData(std::ostream& hFile) const = 0;
    };
}

#endif // DATAVIEW_H
