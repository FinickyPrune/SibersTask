//
//  IndigoViewController.swift
//  Raccoon
//
//  Created by stajer on 27.04.2021.
//

import UIKit

class EditorViewController: UIViewController {
    
    @IBOutlet private weak var saveButton: UIButton!
    @IBOutlet private weak var stringInput: UITextField!
    
    private let saveButtonTitle = "Save"
    private var tmpNumber: Int?
    
    var editorViewModel: EditorViewModel?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        saveButton.setTitle(saveButtonTitle, for: .normal)
        navigationItem.rightBarButtonItem = UIBarButtonItem(title: saveButtonTitle, style: .plain, target: self, action: #selector(saveBarButtonPressed))
        if let string = editorViewModel?.string {
            stringInput.text = string
        }
    }
    
    private func inputHandler(){
        guard let newString = stringInput.text else {
            return
        }
        editorViewModel?.manageNewValue(newString)
    }
    
    @IBAction private func saveButtonPressed(_ sender: Any?) {
        inputHandler()
    }
    
    @objc private func saveBarButtonPressed(){
        inputHandler()
    }
    
}
