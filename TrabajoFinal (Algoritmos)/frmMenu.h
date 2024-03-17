// FRM MENU

#pragma once
#include "MyForm.h"
#include "nivel21.h"
#include "Instrucciones.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmMenu
	/// </summary>
	public ref class frmMenu : public System::Windows::Forms::Form
	{
	public:
		frmMenu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblDr;
	protected:
	private: System::Windows::Forms::Label^ lblBros;
	private: System::Windows::Forms::Button^ btnJugarNiv1;

	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::Button^ btnJugarNiv2;
	private: System::Windows::Forms::Label^ lblEligeNivel;
	private: System::Windows::Forms::Button^ btnInstrucciones;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblDr = (gcnew System::Windows::Forms::Label());
			this->lblBros = (gcnew System::Windows::Forms::Label());
			this->btnJugarNiv1 = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->btnJugarNiv2 = (gcnew System::Windows::Forms::Button());
			this->lblEligeNivel = (gcnew System::Windows::Forms::Label());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblDr
			// 
			this->lblDr->AutoSize = true;
			this->lblDr->BackColor = System::Drawing::Color::Transparent;
			this->lblDr->Font = (gcnew System::Drawing::Font(L"AR DELANEY", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDr->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lblDr->Location = System::Drawing::Point(173, 23);
			this->lblDr->Name = L"lblDr";
			this->lblDr->Size = System::Drawing::Size(112, 58);
			this->lblDr->TabIndex = 0;
			this->lblDr->Text = L"Dr. ";
			this->lblDr->Click += gcnew System::EventHandler(this, &frmMenu::lblDr_Click);
			// 
			// lblBros
			// 
			this->lblBros->AutoSize = true;
			this->lblBros->Font = (gcnew System::Drawing::Font(L"AR DELANEY", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBros->ForeColor = System::Drawing::Color::Blue;
			this->lblBros->Location = System::Drawing::Point(242, 58);
			this->lblBros->Name = L"lblBros";
			this->lblBros->Size = System::Drawing::Size(128, 58);
			this->lblBros->TabIndex = 1;
			this->lblBros->Text = L"Bros";
			// 
			// btnJugarNiv1
			// 
			this->btnJugarNiv1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnJugarNiv1->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJugarNiv1->Location = System::Drawing::Point(164, 251);
			this->btnJugarNiv1->Name = L"btnJugarNiv1";
			this->btnJugarNiv1->Size = System::Drawing::Size(88, 37);
			this->btnJugarNiv1->TabIndex = 2;
			this->btnJugarNiv1->Text = L"Nivel 1";
			this->btnJugarNiv1->UseVisualStyleBackColor = false;
			this->btnJugarNiv1->Click += gcnew System::EventHandler(this, &frmMenu::btnJugar_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Impact", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(202, 314);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(129, 45);
			this->btnSalir->TabIndex = 3;
			this->btnSalir->Text = L"SALIR";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &frmMenu::btnSalir_Click);
			// 
			// btnJugarNiv2
			// 
			this->btnJugarNiv2->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnJugarNiv2->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJugarNiv2->Location = System::Drawing::Point(285, 251);
			this->btnJugarNiv2->Name = L"btnJugarNiv2";
			this->btnJugarNiv2->Size = System::Drawing::Size(85, 37);
			this->btnJugarNiv2->TabIndex = 4;
			this->btnJugarNiv2->Text = L"Nivel 2";
			this->btnJugarNiv2->UseVisualStyleBackColor = false;
			this->btnJugarNiv2->Click += gcnew System::EventHandler(this, &frmMenu::btnJugarNiv2_Click);
			// 
			// lblEligeNivel
			// 
			this->lblEligeNivel->AutoSize = true;
			this->lblEligeNivel->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblEligeNivel->Font = (gcnew System::Drawing::Font(L"Lucida Fax", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEligeNivel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lblEligeNivel->Location = System::Drawing::Point(210, 221);
			this->lblEligeNivel->Name = L"lblEligeNivel";
			this->lblEligeNivel->Size = System::Drawing::Size(110, 18);
			this->lblEligeNivel->TabIndex = 5;
			this->lblEligeNivel->Text = L"Elige el nivel";
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackColor = System::Drawing::Color::RosyBrown;
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"AR JULIAN", 15.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstrucciones->Location = System::Drawing::Point(183, 147);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(165, 35);
			this->btnInstrucciones->TabIndex = 6;
			this->btnInstrucciones->Text = L"Instrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = false;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &frmMenu::btnInstrucciones_Click);
			// 
			// frmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(543, 387);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->lblEligeNivel);
			this->Controls->Add(this->btnJugarNiv2);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnJugarNiv1);
			this->Controls->Add(this->lblBros);
			this->Controls->Add(this->lblDr);
			this->Name = L"frmMenu";
			this->Text = L"frmMenu";
			this->TransparencyKey = System::Drawing::Color::Transparent;
			this->Load += gcnew System::EventHandler(this, &frmMenu::frmMenu_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmMenu_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void lblDr_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnJugar_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm^ frm = gcnew MyForm();
		frm->Show();

	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnJugarNiv2_Click(System::Object^ sender, System::EventArgs^ e) {
		nivel21^ frm2 = gcnew nivel21();
		frm2->Show();
	}
	private: System::Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
		Instrucciones^ frmIns = gcnew Instrucciones();
		frmIns->Show();
	}
	};
}
