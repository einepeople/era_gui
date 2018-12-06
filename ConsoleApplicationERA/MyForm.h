#pragma once


extern "C" {
#include "era_interpreter.h"
}
#include <stdlib.h>   // For _MAX_PATH definition  
#include <stdio.h>  
#include <malloc.h> 

using namespace System::Runtime::InteropServices;


namespace ConsoleApplicationERA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		struct era_t* era;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  runToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  runFullToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  runStepToolStripMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::Label^  label1;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;

			 bool isFileOpened = false;
	public:	MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			era = init_era();
			this->Text = "ERA ASM Inspector";
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  regDGV;
	protected:

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridView^  commandDGV;



	protected:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->regDGV = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->commandDGV = (gcnew System::Windows::Forms::DataGridView());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->runToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->runFullToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->runStepToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->regDGV))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->commandDGV))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// regDGV
			// 
			this->regDGV->AllowUserToAddRows = false;
			this->regDGV->AllowUserToDeleteRows = false;
			this->regDGV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->regDGV->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Column1, this->Column2 });
			this->regDGV->Location = System::Drawing::Point(507, 27);
			this->regDGV->Name = L"regDGV";
			this->regDGV->ReadOnly = true;
			this->regDGV->Size = System::Drawing::Size(311, 632);
			this->regDGV->TabIndex = 0;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Register";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 50;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Value";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// commandDGV
			// 
			this->commandDGV->AllowUserToAddRows = false;
			this->commandDGV->AllowUserToDeleteRows = false;
			this->commandDGV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->commandDGV->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Column3, this->Column4 });
			this->commandDGV->Location = System::Drawing::Point(12, 27);
			this->commandDGV->MultiSelect = false;
			this->commandDGV->Name = L"commandDGV";
			this->commandDGV->ReadOnly = true;
			this->commandDGV->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->commandDGV->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->commandDGV->Size = System::Drawing::Size(489, 695);
			this->commandDGV->TabIndex = 1;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Byte";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Command";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->runToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(830, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->closeToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->closeToolStripMenuItem->Text = L"Close";
			// 
			// runToolStripMenuItem
			// 
			this->runToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->runFullToolStripMenuItem,
					this->runStepToolStripMenuItem
			});
			this->runToolStripMenuItem->Name = L"runToolStripMenuItem";
			this->runToolStripMenuItem->Size = System::Drawing::Size(49, 20);
			this->runToolStripMenuItem->Text = L"Run...";
			// 
			// runFullToolStripMenuItem
			// 
			this->runFullToolStripMenuItem->Name = L"runFullToolStripMenuItem";
			this->runFullToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->runFullToolStripMenuItem->Text = L"Run Full";
			this->runFullToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::runFullToolStripMenuItem_Click);
			// 
			// runStepToolStripMenuItem
			// 
			this->runStepToolStripMenuItem->Name = L"runStepToolStripMenuItem";
			this->runStepToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->runStepToolStripMenuItem->Text = L"Run Step";
			this->runStepToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::runStepToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(507, 662);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"No file opened";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(507, 699);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(159, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Memory size in words";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 256, 0, 0, 0 });
			this->numericUpDown1->Location = System::Drawing::Point(672, 699);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65536, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 64, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(83, 20);
			this->numericUpDown1->TabIndex = 8;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1024, 0, 0, 0 });
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(830, 734);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->commandDGV);
			this->Controls->Add(this->regDGV);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->regDGV))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->commandDGV))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void updateRegs() {
		regDGV->Rows->Clear();
		array<String^>^ row = gcnew array<String^>(2);
		for (int i = 0; i < N_REGISTERS; i++) {
			
			row[0] = String::Concat("REG",i.ToString());
			row[1] = ((uint32_t)era->registers[i]).ToString("X");
			regDGV->Rows->Add(row);
		}
		regDGV->Rows[PC]->Cells[0]->Value = "PC";
		regDGV->Rows[SB]->Cells[0]->Value = "SB";
		regDGV->Rows[SP]->Cells[0]->Value = "SP";
		regDGV->Rows[FP]->Cells[0]->Value = "FP";
	}
	private: System::Void loadFileToForm() {
		commandDGV->Rows->Clear();
		uint32_t elemcount = Convert::ToUInt32(numericUpDown1->Value);
		array<String^>^ row = gcnew array<String^>(2);
		for (int i = 0; i < elemcount; i++) {
			row[0] = i.ToString();
			row[1] = ((uint16_t)era->memory[i]).ToString("X");
			commandDGV->Rows->Add(row);
		}
		updateRegs();
	}
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ o = gcnew OpenFileDialog();
		if (o->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			uint32_t elemcount = Convert::ToUInt32(numericUpDown1->Value);
			free_era(era);
			era = init_era_m(elemcount);
			IntPtr ptrToStr = Marshal::StringToHGlobalAnsi(o->FileName);
			if (read_file(static_cast<char*>(ptrToStr.ToPointer()), era)) {
				MessageBox::Show("Unable to recognize ERA file", "Wrong file",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else {
				this->isFileOpened = true;
				label1->Text = "Opened file: " + o->SafeFileName;
				loadFileToForm();
			}

			Marshal::FreeHGlobal(ptrToStr);
		}
	}
private: System::Void runFullToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	int err = execute(era);
	if (err) {
		if (err == ERA_STATUS_STOP) {
			updateRegs();
			highlightCurrentCommand();
			MessageBox::Show("Execution finished successfully", "Execution finished",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("Error while fully executing, err" + gcnew String(status_what(err)), "Execution error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else {
		updateRegs();
		highlightCurrentCommand();
	}
}
private: System::Void runStepToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	int err = step(era);
	if (err) {
		if (err == ERA_STATUS_STOP) {
			updateRegs();
			highlightCurrentCommand();
			MessageBox::Show("Execution finished successfully", "Execution finished",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			
			MessageBox::Show("Error while step executing, err = " + gcnew String(status_what(err)), "Execution error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else {
		updateRegs();
		highlightCurrentCommand();
	}
}
		 private: System::Void highlightCurrentCommand() {
			 int a = Convert::ToUInt32(regDGV->Rows[PC]->Cells[1]->Value);
			 commandDGV->Rows[a]->Selected = true;
		 }
};
}
