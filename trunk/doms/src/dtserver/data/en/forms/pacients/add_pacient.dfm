<Form title="Ingresar paciente" tables="doms_persons doms_pacients" >
	<HBox>
		<Image filename="logo.svg" width="100" height="100" />
		<VBox>
			<Label text="&lt;H1&gt;Ingresar pacientes&lt;/h1&gt;" />
			<Input type="date" />
		</VBox>
	</HBox>
	<VGroupBox title="Informacion personal" >
		<Input label="Historia clinica" dbfield="doms_pacients:clinicHistory" />
		<HBox>
			<Input label="Nombres" dbfield="doms_persons:name" />
			<Input label="Apellidos" dbfield="doms_persons:lastName" />
		</HBox>
		<HBox>
			<Input type="options" label="Sexo" orientation="0" dbfield="doms_persons:genre" >
				<RadioButton label="Masculino" id="0" />
				<RadioButton label="Femenino" id="1" />
			</Input>
			<Input type="options" label="Estado civil" orientation="0" dbfield="doms_persons:civilState" >
				<RadioButton label="Soltero" id="0" />
				<RadioButton label="Casado" id="1" />
				<RadioButton label="Viudo" id="2" />
				<RadioButton label="Union libre" id="3" />
			</Input>
			<Input type="options" label="Documento de identidad" orientation="0" dbfield="doms_persons:idDocumentType" >
				<RadioButton label="Tarjeta de identidad" id="0" />
				<RadioButton label="Cedula de ciudadania" id="1" />
				<RadioButton label="Cedula extrajera" id="2" />
				<RadioButton label="Pasaporte" id="3" />
				<Input label="No." dbfield="doms_persons:idDocument->doms_pacients:idDocument" />
			</Input>
		</HBox>
		<HBox>
			<Input label="Direccion de residencia" dbfield="doms_persons:address"  />
			<Input label="Ciudad"  dbfield="doms_persons:currentCity" />
		</HBox>
		<HBox>
			<Input label="Telefono de residencia" dbfield="doms_persons:phone"  />
			<Input label="Movil" dbfield="doms_persons:cellular" />
			<Input label="E-Mail" dbfield="doms_persons:email" />
		</HBox>
		<HBox>
			<Input label="Ocupacion" dbfield="doms_pacients:occupation" />
			<Input label="Telefono oficina" dbfield="doms_pacients:workPhone" />
		</HBox>
	</VGroupBox>
	<VGroupBox title="Referencias personales" >
		<HBox>
			<Input label="Persona responsable" dbfield="doms_pacients:responsiblePerson" />
			<Input label="Parentesco" dbfield="doms_pacients:responsibleRelationchip" />
			<Input label="telefono" dbfield="doms_pacients:responsiblePhone" />
			<Input label="ocupacion" dbfield="doms_pacients:responsibleOccupation" />
		</HBox>
		<HBox>
			<Input label="Persona de referencia" dbfield="doms_pacients:referenceName" />
			<Input label="Parentesco" dbfield="doms_pacients:referenceRelationchip" />
			<Input label="telefono" dbfield="doms_pacients:referenePhone" />
			<Input label="ocupacion" dbfield="doms_pacients:referenceOccupation" />
		</HBox>
	</VGroupBox>
</Form>

