//
//  IndigoViewController.swift
//  Raccoon
//
//  Created by stajer on 27.04.2021.
//

import UIKit

protocol EditorDelegate: class {
    func didSubmit(_ sender: EditorViewController, value: Int)
}

class EditorViewController: UIViewController {
    
    @IBOutlet private weak var saveButton: UIButton!
    @IBOutlet private weak var numberInput: UITextField!
    
    private let saveButtonTitle = "Save"
    private var tmpNumber: Int?
    
    weak var delegate: EditorDelegate?
    
    func setNumberInputValue(value: Int) {
        tmpNumber = value
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        if let tmpNumber = tmpNumber {
            numberInput.text = String(tmpNumber)
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        saveButton.setTitle(saveButtonTitle, for: .normal)
        navigationItem.rightBarButtonItem = UIBarButtonItem(title: saveButtonTitle, style: .plain, target: self, action: #selector(saveBarButtonPressed))
        
    }
    
    private func inputHandler(){
        guard let newNumberString = numberInput.text, let newNumber = Int(newNumberString) else {
            return
        }
        delegate?.didSubmit(self, value: newNumber)
    }
    
    @IBAction private func saveButtonPressed(_ sender: Any?) {
        inputHandler()
    }
    
    @objc private func saveBarButtonPressed(){
        inputHandler()
    }
    
}
