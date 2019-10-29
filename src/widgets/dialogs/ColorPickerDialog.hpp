#pragma once

#include "widgets/BaseWindow.hpp"

#include <pajlada/signals/signal.hpp>

namespace chatterino {

class ColorPickerDialog : public BaseWindow
{
public:
    ColorPickerDialog(QWidget *parent = nullptr);

    QColor getSelectedColor() const;

    pajlada::Signals::NoArgSignal closed;

private:
    struct {
        // TODO(leon)
        QLineEdit *htmlEdit;
        QPushButton *colorPreview;
    } ui_;
};

}  // namespace chatterino
