#pragma once
#include "Mario.h"
#include"Controller.h"
#include <ctime>

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmMain
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			srand(time(NULL));
			InitializeComponent();
			g = pnlCanvas->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, pnlCanvas->ClientRectangle);
			bmpHero = gcnew Bitmap("Mario1.png");
			bmpMap = gcnew Bitmap("fondo.png");
			bmpayudin = gcnew Bitmap("Ayudante.png");
			enemy = gcnew Bitmap("Enemy.png");
			bmpJefe = gcnew Bitmap("JefeFinal.png");
			bmpmeds = gcnew Bitmap("medicamento.png");
			mario = new Mario(bmpHero->Width / 4, bmpHero->Height / 4);
			controller = new Controller();
			controller->createEnemies(enemy->Width / 10, enemy->Height / 2);
			controller->createJefeFinal(bmpJefe->Width, bmpJefe->Height);
			controller->CreateMedicamento(bmpmeds->Width, bmpmeds->Height);
		}
	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ lblvidas;
	private: System::Windows::Forms::Panel^ pnlCanvas;
	protected:
	private: System::ComponentModel::IContainer^ components;
	private:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ bmpHero;
		Bitmap^ bmpMap;
		Bitmap^ bmpayudin;
		Bitmap^ enemy;
		Bitmap^ bmpJefe;
		Bitmap^ bmpmeds;

		Mario* mario;
		Controller* controller;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblvidas = (gcnew System::Windows::Forms::Label());
			this->pnlCanvas = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// lblvidas
			// 
			this->lblvidas->AutoSize = true;
			this->lblvidas->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblvidas->Location = System::Drawing::Point(12, 9);
			this->lblvidas->Name = L"lblvidas";
			this->lblvidas->Size = System::Drawing::Size(58, 24);
			this->lblvidas->TabIndex = 0;
			this->lblvidas->Text = L"Vidas";
			// 
			// pnlCanvas
			// 
			this->pnlCanvas->Location = System::Drawing::Point(0, 2);
			this->pnlCanvas->Name = L"pnlCanvas";
			this->pnlCanvas->Size = System::Drawing::Size(1182, 745);
			this->pnlCanvas->TabIndex = 0;
			this->pnlCanvas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pnlCanvas_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1184, 749);
			this->Controls->Add(this->lblvidas);
			this->Controls->Add(this->pnlCanvas);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::presionar);
			this->ResumeLayout(false);
			this->PerformLayout();


		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//clear
		buffer->Graphics->Clear(Color::WhiteSmoke);

		//move para el personaje se hara con teclas
		controller->moveEveryThing(buffer->Graphics, mario->getx());

		//draw
		buffer->Graphics->DrawImage(bmpMap, 0, 0, bmpMap->Width * 2.2, bmpMap->Height * 1.6);
		controller->drawEveryThing(buffer->Graphics, bmpayudin, enemy, bmpJefe, bmpHero, bmpmeds);
		mario->mostrar(buffer->Graphics, bmpHero);
		lblvidas->Text = "Vidas: " + controller->getMario()->getVidas();

		//Render
		buffer->Render(g);

		// --- COLISIONES --- 

		controller->Colisiones(buffer->Graphics, mario);
		if (mario->getVidas() == 0) {
			this->timer1->Enabled = false;
			MessageBox::Show("PERDISTE. Tienes 0 vidas");
			this->Close();

		}

		if (mario->getx() + mario->getancho() == g->VisibleClipBounds.Width) { // si mario llega al final de la pantalla
			timer1->Enabled = false;
			MessageBox::Show("LEVEL 1 PASSED SUCCESFULLY. NEW POWER UNLOCKED.");
			this->Close();
		}

	}

	private: System::Void presionar(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A:
			mario->mover(buffer->Graphics, 'A', bmpHero); break;
		case Keys::D:
			mario->mover(buffer->Graphics, 'D', bmpHero); break;
		case Keys::W:
			mario->mover(buffer->Graphics, 'W', bmpHero); break;
		case Keys::S:
			mario->mover(buffer->Graphics, 'S', bmpHero); break;

		case Keys::Space:
			mario->mover(buffer->Graphics, ' ', bmpHero); break;
			// AYUDANTE
		case Keys::F:
			Ayudante* a = new Ayudante(bmpayudin->Width / 12, bmpayudin->Height / 8);
			controller->createAyudante(a);


		}

	}
	private: System::Void pnlCanvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	};
}

