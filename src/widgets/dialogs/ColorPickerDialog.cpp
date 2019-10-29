#include "widgets/dialogs/ColorPickerDialog.hpp"

#include "util/LayoutCreator.hpp"

namespace chatterino {

ColorPickerDialog::ColorPickerDialog(QWidget *parent)
    : BaseWindow(BaseWindow::EnableCustomFrame, parent)
{
    this->setWindowTitle("Color Picker");

    LayoutCreator<QWidget> layoutWidget(this->getLayoutContainer());
    auto layout = layoutWidget.setLayoutType<QVBoxLayout>().withoutMargin();

    {
        LayoutCreator<QWidget> obj(new QWidget());
        auto hbox = obj.setLayoutType<QHBoxLayout>();

        hbox.emplace<QLabel>("test:");
        auto edit = hbox.emplace<QLineEdit>().assign(&this->ui_.htmlEdit);
        auto colPre =
            hbox.emplace<QPushButton>().assign(&this->ui_.colorPreview);

        QObject::connect(edit.getElement(), &QLineEdit::returnPressed, [this] {
            QColor parsed(this->ui_.htmlEdit->text());
            qDebug() << parsed;

            QPalette p;
            p.setColor(QPalette::Button, parsed);
            this->ui_.colorPreview->setPalette(p);
        });

        layout.append<QWidget>(obj.getElement());
    }
}

}  // namespace chatterino
