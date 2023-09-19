#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Neurona::Neurona()
{
    id=0;
    voltaje=0;
    posicion_x=0;
    posicion_y=0;
    red=0;
    green=0;
    blue=0;
    sig=nullptr;
}

Neurona::Neurona(int id,float voltaje,int posicion_x,int posicion_y,int red,int green,int blue,Neurona *sig){
    this->id=id;
    this->voltaje=voltaje;
    this->posicion_x=posicion_x;
    this->posicion_y=posicion_y;
    this->red=red;
    this->blue=blue;
    this->green=green;
    this->sig=sig;
}

void Admin::agregar_inicio(int id,float voltaje,int posicion_x,int posicion_y,int red,int green,int blue)
{
    Neurona *tmp=new Neurona(id,voltaje,posicion_x,posicion_y,red,green,blue,nullptr);
    if(!h){
        h=tmp;
    }else{
        tmp->sig=h;
        h=tmp;
    }
}

void Admin::agregar_final(int id,float voltaje,int posicion_x,int posicion_y,int red,int green,int blue){
    Neurona *tmp=new Neurona(id,voltaje,posicion_x,posicion_y,red,green,blue,nullptr);
    if(!h){
        h=tmp;
    }else{
        Neurona *aux = h;
        while (aux->sig != nullptr) {
            aux = aux->sig;
        }
        aux->sig = tmp;
    }
}

void Admin::mostrar(){
    Neurona *aux=h;
    if(h){
        while(aux){
            cout<<"Neurona_"<<aux->id<<endl;
            cout<<"Voltaje: "<<aux->voltaje<<endl;
            cout<<"posicion en X: "<<aux->posicion_x<<endl;
            cout<<"Posicion en Y: "<<aux->posicion_y<<endl;
            cout<<"R: "<<aux->red<<endl;
            cout<<"G: "<<aux->green<<endl;
            cout<<"B: "<<aux->blue<<endl;
            aux=aux->sig;
        }
    }
    else{
        cout<<"La lista se encuentra vacía"<<endl;
    }

}

Admin *lis = new Admin();
void Admin::buscar(int id)
{
    Neurona* aux = lis->h;
    while (aux != nullptr)
    {
        if (aux->id == id)
        {
            cout<<"ID: "<<aux->id<<endl;
            cout<<"Voltaje: "<<aux->voltaje<<endl;
            cout<<"Posicion X: "<<aux->posicion_x<<endl;
            cout<<"Posicion Y: "<<aux->posicion_y<<endl;
            cout<<"R: "<<aux->red<<endl;
            cout<<"G: "<<aux->green<<endl;
            cout<<"B: "<<aux->blue<<endl;
        }
        aux = aux->sig;
    }
    if(aux==nullptr)
    {
        cout<<"No se ha encontrado la neurona"<<endl;
    }
}

int id,posicion_x,posicion_y,red,green,blue,busc;
float voltaje;

void MainWindow::limpiarCampos() {
    id = 0;
    voltaje = 0.0;
    posicion_x = 0;
    posicion_y = 0;
    red = 0;
    green = 0;
    blue = 0;
    busc = 0;

    ui->insert_id->clear();
    ui->insert_voltaje->clear();
    ui->pos_x->setValue(0);
    ui->pos_y->setValue(0);
    ui->set_red->setValue(0);
    ui->set_green->setValue(0);
    ui->set_blue->setValue(0);
    ui->spinBox->setValue(0);
}

void MainWindow::on_insert_id_textChanged(const QString &arg1)
{
    string cadenaStd = arg1.toStdString();

    bool esNumeroValido = !cadenaStd.empty() && std::all_of(cadenaStd.begin(), cadenaStd.end(), [](char c) {
        return isdigit(static_cast<unsigned char>(c));
    });

    if (esNumeroValido)
    {
        id = stoi(cadenaStd);
    }
    else
    {
        id = 0; // Valor predeterminado
    }
}

void MainWindow::on_insert_voltaje_textChanged(const QString &arg1)
{
    string cadenaStd = arg1.toStdString();

    try {
        voltaje = stof(cadenaStd);
    } catch (const invalid_argument& e) {
        voltaje = numeric_limits<float>::quiet_NaN();
    }
}

void MainWindow::on_pos_x_valueChanged(int value)
{
    posicion_x = value;
}

void MainWindow::on_pos_y_valueChanged(int value)
{
    posicion_y = value;
}

void MainWindow::on_set_red_valueChanged(int value)
{
    red = value;
}

void MainWindow::on_set_green_valueChanged(int value)
{
    green = value;
}

void MainWindow::on_set_blue_valueChanged(int value)
{
    blue = value;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    busc=arg1;
}



void MainWindow::on_buscarNeurona_clicked()
{
    lis->buscar(busc);
    limpiarCampos();
}



void MainWindow::on_agregarInicio_clicked()
{
    lis->agregar_inicio(id,voltaje,posicion_x,posicion_y,red,green,blue);
    limpiarCampos();
}


void MainWindow::on_AgregarFinal_clicked()
{
    lis->agregar_final(id,voltaje,posicion_x,posicion_y,red,green,blue);
    limpiarCampos();
}

void MainWindow::on_mostrar_clicked()
{
    QString neuronasInfo;

    Neurona *aux = lis->h;
    if (aux) {
        while (aux)
        {
            QString neuronaStr = "Neurona_" + QString::number(aux->id) + ":\n";
            neuronaStr += "Voltaje: " + QString::number(aux->voltaje) + "\n";
            neuronaStr += "Posicion X: " + QString::number(aux->posicion_x) + "\n";
            neuronaStr += "Posicion Y: " + QString::number(aux->posicion_y) + "\n";
            neuronaStr += "R: " + QString::number(aux->red) + "\n";
            neuronaStr += "G: " + QString::number(aux->green) + "\n";
            neuronaStr += "B: " + QString::number(aux->blue) + "\n\n";

            // Agregar la información de la neurona a la cadena principal
            neuronasInfo += neuronaStr;

            aux = aux->sig;
        }
    }
    else
    {
        neuronasInfo = "La lista se encuentra vacía";
    }

    ui->plainTextEdit->setPlainText(neuronasInfo);
}

void MainWindow::on_Tabla_clicked()
{

    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setRowCount(4);
    QTableWidgetItem *Myitem=new QTableWidgetItem("1");
    ui->tableWidget->setItem(0,0,Myitem);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Abrir archivo"), "/home", tr("Archivos de texto (*.txt)"));

    if (!filename.isEmpty())
    {
        QFile file(filename);
        if (file.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream in(&file);

            while (!in.atEnd())
            {
                QString line = in.readLine();
                QStringList parts = line.split('|');
                if (parts.size() == 7)
                {
                    int id = parts[0].toInt();
                    float voltaje = parts[1].toFloat();
                    int posicion_x = parts[2].toInt();
                    int posicion_y = parts[3].toInt();
                    int red = parts[4].toInt();
                    int green = parts[5].toInt();
                    int blue = parts[6].toInt();
                    lis->agregar_final(id, voltaje, posicion_x, posicion_y, red, green, blue);
                }
            }

            file.close();
            QMessageBox::information(this, "Éxito", "Lista de neuronas cargada desde el archivo.");
        }
        else
        {
            QMessageBox::warning(this, "Error", "No se pudo abrir el archivo para lectura.");
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    //Guardar
    QString filename = QFileDialog::getSaveFileName(this, tr("Guardar archivo"), "/home", tr("Archivos de texto (*.txt)"));

    if (!filename.isEmpty())
    {
        QFile file(filename);
        if (file.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream out(&file);
            Neurona *aux = lis->h;
            while (aux)
            {
                out << aux->id << '|' << aux->voltaje << '|'
                    << aux->posicion_x << '|' << aux->posicion_y << '|'
                    << aux->red << '|' << aux->green << '|' << aux->blue << '\n';
                aux = aux->sig;
            }
            file.close();
            QMessageBox::information(this, "Éxito", "Lista de neuronas guardada en el archivo.");
        }
        else
        {
            QMessageBox::warning(this, "Error", "No se pudo abrir el archivo para escritura.");
        }
    }
}

