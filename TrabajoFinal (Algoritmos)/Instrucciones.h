#pragma once

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Instrucciones
	/// </summary>
	public ref class Instrucciones : public System::Windows::Forms::Form
	{
	public:
		Instrucciones(void)
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
		~Instrucciones()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Engravers MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(78, 71);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(192, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"A --> Izquierda";
			this->label1->Click += gcnew System::EventHandler(this, &Instrucciones::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Engravers MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Location = System::Drawing::Point(78, 99);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(175, 19);
			this->label2->TabIndex = 1;
			this->label2->Text = L"D --> Derecha";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Engravers MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label3->Location = System::Drawing::Point(104, 257);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(166, 19);
			this->label3->TabIndex = 2;
			this->label3->Text = L"O --> Dispara";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Engravers MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label4->Location = System::Drawing::Point(78, 130);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(151, 19);
			this->label4->TabIndex = 3;
			this->label4->Text = L"W--> ARRIBA";
			this->label4->Click += gcnew System::EventHandler(this, &Instrucciones::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Engravers MT", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Navy;
			this->label5->Location = System::Drawing::Point(81, 37);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(189, 25);
			this->label5->TabIndex = 4;
			this->label5->Text = L"CONTROLES";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Engravers MT", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Navy;
			this->label6->Location = System::Drawing::Point(144, 222);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(98, 25);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Niv. 2";
			this->label6->Click += gcnew System::EventHandler(this, &Instrucciones::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Engravers MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label7->Location = System::Drawing::Point(78, 188);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(190, 19);
			this->label7->TabIndex = 6;
			this->label7->Text = L"F --> Ayudante";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label8->Font = (gcnew System::Drawing::Font(L"Engravers MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Fuchsia;
			this->label8->Location = System::Drawing::Point(408, 84);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(125, 19);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Creditos";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label9->Font = (gcnew System::Drawing::Font(L"Engravers MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Fuchsia;
			this->label9->Location = System::Drawing::Point(412, 121);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(262, 19);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Alejandro Cuadros";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label10->Font = (gcnew System::Drawing::Font(L"Engravers MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Fuchsia;
			this->label10->Location = System::Drawing::Point(412, 186);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(154, 19);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Jose Quispe";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label11->Font = (gcnew System::Drawing::Font(L"Engravers MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Fuchsia;
			this->label11->Location = System::Drawing::Point(412, 155);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(220, 19);
			this->label11->TabIndex = 10;
			this->label11->Text = L"Anderson Gonza";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Engravers MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label12->Location = System::Drawing::Point(78, 164);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(129, 19);
			this->label12->TabIndex = 11;
			this->label12->Text = L"S--> ABAJO";
			this->label12->Click += gcnew System::EventHandler(this, &Instrucciones::label12_Click);
			// 
			// Instrucciones
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(701, 305);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Instrucciones";
			this->Text = L"Instrucciones";
			this->Load += gcnew System::EventHandler(this, &Instrucciones::Instrucciones_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Instrucciones_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
