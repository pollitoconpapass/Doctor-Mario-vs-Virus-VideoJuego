//nivel21

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
	public ref class nivel21 : public System::Windows::Forms::Form
	{
	public:
		nivel21(void)
		{
			srand(time(NULL));
			InitializeComponent();
			g = pnlCanvas->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, pnlCanvas->ClientRectangle);
			bmpHero = gcnew Bitmap("Mario1.png");
			bmpMap = gcnew Bitmap("fondo2.png");
			bmpEnemy = gcnew Bitmap("Enemy.png");
			bmpJefe = gcnew Bitmap("JefeFinal.png");
			mario1 = new Mario(bmpHero->Width / 4, bmpHero->Height / 4);
			jefe2 = new JefeFinal(bmpJefe->Width, bmpJefe->Height);
			controller = new Controller();
			controller->createJefeFinal(bmpJefe->Width, bmpJefe->Height);
			controller->createEnemy2(bmpEnemy->Width / 10, bmpEnemy->Height / 2);

		}
	protected:
		~nivel21()
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
		Bitmap^ bmpEnemy;
		Bitmap^ bmpJefe;
		Mario* mario1;
		Controller* controller;
		JefeFinal* jefe2;

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
			this->timer1->Tick += gcnew System::EventHandler(this, &nivel21::timer1_Tick);
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
			this->pnlCanvas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &nivel21::pnlCanvas_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1100, 749);
			this->Controls->Add(this->lblvidas);
			this->Controls->Add(this->pnlCanvas);
			this->Name = L"nivel21";
			this->Text = L"nivel21";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &nivel21::presionar);
			this->ResumeLayout(false);
			this->PerformLayout();


		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//clear
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//collision

		//move para el personaje se hara con teclas
		controller->moveEveryThingNiv2(buffer->Graphics, mario1->getx());

		//draw
		buffer->Graphics->DrawImage(bmpMap, 0, 0, bmpMap->Width * 1.4, bmpMap->Height * 1.2);
		controller->drawEveryThingNiv2(buffer->Graphics, bmpJefe, bmpHero, bmpEnemy);
		mario1->mostrar(buffer->Graphics, bmpHero);
		lblvidas->Text = "Vidas: " + controller->getMario()->getVidas();

		//Render
		buffer->Render(g);

		// --- COLISIONES --- 

		controller->ColisionesNiv2(buffer->Graphics, mario1);
		if (mario1->getVidas() == 0) {
			this->timer1->Enabled = false;
			MessageBox::Show("PERDISTE. Tienes 0 vidas");
		}

		// Ganador Nivel 2
		if (jefe2->getvidas() == 0) {
			timer1->Enabled = false;
			MessageBox::Show("LEVEL 2. PASSED SUCCESFULLY");
			this->Close();
		}

	}

	private: System::Void presionar(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A:
			mario1->mover(buffer->Graphics, 'A', bmpHero); break;
		case Keys::D:
			mario1->mover(buffer->Graphics, 'D', bmpHero); break;
		case Keys::W:
			mario1->mover(buffer->Graphics, 'W', bmpHero); break;
		case Keys::S:
			mario1->mover(buffer->Graphics, 'S', bmpHero); break;

		case Keys::Space:
			mario1->mover(buffer->Graphics, ' ', bmpHero); break;
			// AYUDANTE
		case Keys::O:
			Bullets* b = new Bullets(mario1->getx(), mario1->gety(), mario1->getindex());
			controller->agregar_disparo(b);

			break;


		}

	}
	private: System::Void pnlCanvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	};
}

