//
//  EditorViewModel.swift
//  Raccoon
//
//  Created by stajer on 04.05.2021.
//

import Foundation

protocol EditorViewModelDelegate: class {
    func didSubmitValue(_ seder: EditorViewModel, value: Int)
}


class EditorViewModel {
    weak var delegate: EditorViewModelDelegate?
    let number: Int?
    
    init(_ value: Int?) {
        number = value
    }
    
    func manageNewNumber(_ value: Int) {
        delegate?.didSubmitValue(self, value: value)
    }
}
